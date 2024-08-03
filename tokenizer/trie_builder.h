#pragma once



// umba::tokenizer::
namespace umba {
namespace tokenizer {



//----------------------------------------------------------------------------
// Префиксные деревья (без них таки никак)
// https://ru.hexlet.io/courses/algorithms-trees/lessons/prefix/theory_unit
// https://habr.com/ru/companies/otus/articles/676692/
// https://otus.ru/nest/post/676/

class TrieBuilder
{

protected:

public:

    struct TrieBuilderMapNode
    {
        TrieNode                                    trieNode ;
        std::map<token_type, TrieBuilderMapNode>    childs   ;
        trie_index_type                             nodeIndex;
        trie_index_type                             level    ;

        TrieBuilderMapNode() : trieNode(), childs()
        {
            trieNodeInitMakeUninitialized(trieNode);
        }

        TrieBuilderMapNode(const TrieBuilderMapNode &) = default;
        TrieBuilderMapNode& operator=(const TrieBuilderMapNode &) = default;
        TrieBuilderMapNode(TrieBuilderMapNode &&) = default;
        TrieBuilderMapNode& operator=(TrieBuilderMapNode &&) = default;

    };

    typedef std::map<token_type, TrieBuilderMapNode> TrieNodesMap;


public: // пока public, потом, скорее всего, будет спрятано

    TrieNodesMap     m_trieNodesMap;

public:


    template<typename TokenSequenceIterator>
    TrieNode& addTokenSequence(TokenSequenceIterator b, TokenSequenceIterator e, payload_type payload)
    {
        //UMBA_ASSERT(!seqStr.empty());
        UMBA_ASSERT(b!=e);

        TrieNodesMap *pCurMap  = &m_trieNodesMap;
        TrieBuilderMapNode  *pCurNode = 0;

        //for(auto ch: seqStr)
        for(; b!=e; ++b)
        {
            TrieNodesMap
            &curMap  = *pCurMap;
            pCurNode = &curMap[*b]; // .second;
            pCurMap  = &pCurNode->childs;

            pCurNode->trieNode.token = static_cast<token_type>(*b);

            // ++finalTableNumEntries;
        }

        // Прошагали всё символы обрабатываемой строки
        // Финальный узел у нас есть

        if (pCurNode->trieNode.payload!=token_id_invalid && pCurNode->trieNode.payload!=payload)
            return pCurNode->trieNode; // Такой путь в дереве уже есть, и там другой корректный идентификатор токена

        // Записываем туда идентификатор оператора
        pCurNode->trieNode.payload = payload;

        return pCurNode->trieNode;
    }

    TrieNode& addTokenSequence(const std::string &seqStr, payload_type payload)
    {
        return addTokenSequence(seqStr.begin(), seqStr.end(), payload);
    }

    TrieNode& addTokenSequence(char ch, payload_type payload)
    {
        const char *pCh = &ch;
        return addTokenSequence(pCh, pCh+1, payload);
    }


    template<typename ContainerType>
    void buildTokenTrie(ContainerType &buildTo) const
    {
        buildTo.clear();

        struct QueItem
        {
            umba::tokenizer::TrieBuilder::TrieNodesMap   *pMap;
            umba::tokenizer::trie_index_type             level;
            umba::tokenizer::trie_index_type             parentNodeIndex;
        };

        TrieNodesMap trieNodesMapCopy = m_trieNodesMap;

        std::deque<QueItem>  que;
        que.emplace_back( QueItem{ &trieNodesMapCopy
                                 , 0u                                    // level
                                 , trie_index_invalid  // parentNodeIndex
                                 }
                        );

        std::size_t nodeIdx = 0;
        while(!que.empty())
        {
            QueItem qi = que.front();  que.pop_front();
            auto &m = *qi.pMap;
            for(auto &kv : m)
            {
                kv.second.nodeIndex = nodeIdx++;
                kv.second.level     = qi.level;
                if (!kv.second.childs.empty())
                {
                    que.emplace_back(QueItem{&kv.second.childs, kv.second.level+1u });
                }
            }
        }

        que.emplace_back( QueItem{ &trieNodesMapCopy
                                 , 0u                                    // level
                                 , trie_index_invalid  // parentNodeIndex
                                 }
                        );

        while(!que.empty())
        {
            QueItem qi = que.front();  que.pop_front();
            auto &m = *qi.pMap;
            std::size_t curParentNodeIndex = qi.parentNodeIndex;

            if (m.empty())
            {
                continue;
            }

            umba::tokenizer::trie_index_type lookupChunkStartIndex = m.begin()->second.nodeIndex;
            for(auto &kv : m)
            {
                buildTo.emplace_back(kv.second.trieNode); // tokenId тут уже настроен, а childsIndex - инвалид
                buildTo.back().parentNodeIndex       = curParentNodeIndex;
                buildTo.back().lookupChunkStartIndex = lookupChunkStartIndex;
                buildTo.back().lookupChunkSize       = m.size();
                buildTo.back().token                 = kv.first;
#if !defined(UMBA_TOKENIZER_TRIE_NODE_LEVEL_FIELD_DISABLE)
                buildTo.back().level                 = qi.level;
#endif
                if (!kv.second.childs.empty())
                {
                    buildTo.back().childsIndex = kv.second.childs.begin()->second.nodeIndex;
                    que.emplace_back(QueItem{&kv.second.childs, kv.second.level+1u, kv.second.nodeIndex});
                }
            }
        }

    }

}; // class TrieBuilder

//----------------------------------------------------------------------------





} // namespace tokenizer
} // namespace umba

