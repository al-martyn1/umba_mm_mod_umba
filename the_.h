// https://rsdn.org/forum/cpp.applied/8544625.1
// https://rsdn.org/forum/cpp.applied/8555847.1
// https://habr.com/ru/articles/248897/
// https://habr.com/ru/articles/228031/
// https://en.cppreference.com/w/cpp/language/parameter_pack
// C++20 idioms for parameter packs - https://www.scs.stanford.edu/~dm/blog/param-pack.html


#include "rule_of_five.h"


// Автоматическое выведение типа аргумента (Class template argument deduction /CTAD) не работает для алиасов в GCC 7.3
// Это не работает, а для оригинального типа работает
// template<typename TValue> using TheValue = umba::TheValue<TValue>;
// template<typename TFlags> using TheFlags = umba::TheFlags<TFlags>;

// Поэтому либо используем шаблон из NS umba, либо вместо алиасов подключаем в нужном NS этот файлик ("the_.h")


template<typename TVal>
class TheValue
{

    const TVal &tVal;


public:

    UMBA_RULE_OF_FIVE(TheValue, delete, delete, delete, delete, delete);

    constexpr explicit TheValue(const TVal& v) noexcept
      : tVal(v)
    {
    }

    template <typename... TArgs>
    constexpr
    bool oneOf(TArgs&&... args) const
    {
        return ((tVal == args) || ...);
    }

    template <auto... VArgs>
    constexpr
    bool oneOf() const
    {
        return ((tVal == VArgs) || ...);
    }

}; // class TheValue





template<typename TFlags>
class TheFlags
{

    const TFlags &tFlags;

    // template <typename... TArgs>
    // constexpr static
    // TFlags orImpl(TArgs&&... args)


public:

    UMBA_RULE_OF_FIVE(TheFlags, delete, delete, delete, delete, delete);

    constexpr explicit TheFlags(const TFlags& f) noexcept
      : tFlags(f)
    {
    }

    template <typename... TArgs>
    constexpr
    bool oneOf(TArgs&&... args) const
    {
        auto flags = ((TFlags)0 | ... | args); //  | &args
        return (tFlags & flags)!=(TFlags)0;
    }

    template <auto... VArgs>
    constexpr
    bool oneOf() const
    {
        auto flags = ((TFlags)0 | ... | VArgs);
        return (tFlags & flags)!=(TFlags)0;
    }

    template <typename... TArgs>
    constexpr
    bool allOf(TArgs&&... args) const
    {
        auto flags = ((TFlags)0 | ... | args);
        return (tFlags & flags)==flags;
    }

    template <auto... VArgs>
    constexpr
    bool allOf() const
    {
        auto flags = ((TFlags)0 | ... | VArgs);
        return (tFlags & flags)==flags;
    }

}; // class TheFlags



