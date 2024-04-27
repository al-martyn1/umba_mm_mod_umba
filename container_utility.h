#pragma once

namespace umba {



//----------------------------------------------------------------------------
template <typename SetType> inline
SetType updatedSet(const SetType &s, typename SetType::key_type k, bool bAddKey /*else remove*/)
{
    SetType sCopy = s;
    if (bAddKey)
    {
        sCopy.insert(k);
    }
    else
    {
        sCopy.erase(k);
    }

    return sCopy;
}

//----------------------------------------------------------------------------
template<typename VectorType> inline
void vectorPushBack(VectorType &pushBackTo, const VectorType &pushFrom)
{
    pushBackTo.insert( pushBackTo.end(), pushFrom.begin(), pushFrom.end() );
}



} // namespace umba


