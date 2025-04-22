#pragma once


#include "rule_of_five.h"


namespace umba {

#include "the_.h"


} // namespace umba


#include <type_traits>



// Старые компиляторы не всегда умеют выводить тип параметра шаблона
// из фактически переданных параметров
// Также, иногда, для базового типа это работает,
// но если мы делаем alias при помощи шаблонного using,
// работоспособность ломается

#define UMBA_THE_VALUE(v)     umba::TheValue< std::decay_t<decltype(v)> >(v)
#define UMBA_THE_FLAGS(v)     umba::TheFlags< std::decay_t<decltype(v)> >(v)
