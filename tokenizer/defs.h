#pragma once



// umba::tokenizer::
namespace umba {
namespace tokenizer {


//----------------------------------------------------------------------------
using  trie_index_type                                     = UMBA_TOKENIZER_TRIE_INDEX_TYPE;
inline constexpr const trie_index_type trie_index_invalid  = UMBA_TOKENIZER_TRIE_INDEX_INVALID;
//inline constexpr const trie_index_type trie_index_initial  = UMBA_TOKENIZER_TRIE_INDEX_INITIAL;

//----------------------------------------------------------------------------
using  token_type                                          = UMBA_TOKENIZER_TOKEN_TYPE;
inline constexpr const token_type token_id_invalid         = UMBA_TOKENIZER_TOKEN_INVALID;

//----------------------------------------------------------------------------
using  payload_type                                        = UMBA_TOKENIZER_PAYLOAD_TYPE;
inline constexpr const payload_type payload_invalid        = UMBA_TOKENIZER_PAYLOAD_INVALID;

//----------------------------------------------------------------------------
using payload_flags_type                                   = UMBA_TOKENIZER_PAYLOAD_FLAGS_TYPE;

//----------------------------------------------------------------------------
using TrieNode = umba_tokenizer_trie_node;

//----------------------------------------------------------------------------



} // namespace tokenizer
} // namespace umba

