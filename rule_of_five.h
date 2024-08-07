/*!
    \file
    \brief Макросы для правила пяти - надоело руками выписывать. Правило пяти - https://habr.com/ru/companies/otus/articles/800089/
 */
#pragma once


//! Часть правила пяти для конструктора по умолчанию
/*!
    UMBA_RULE_OF_FIVE_DEF(className, default|delete);
*/
#define  UMBA_RULE_OF_FIVE_DEF(className, ctorDef) \
         className() = ctorDef



//! Часть правила пяти для конструктора и оператора копирования
/*!
    UMBA_RULE_OF_FIVE_COPY(className, default|delete, default|delete);
*/
#define  UMBA_RULE_OF_FIVE_COPY(className, ctorCopy, opCopy) \
         className(const className &) = ctorCopy;            \
         className& operator=(const className &) = opCopy



//! Часть правила пяти для конструктора и оператора перемещения
/*!
    UMBA_RULE_OF_FIVE_MOVE(className, default|delete, default|delete);
*/
#define  UMBA_RULE_OF_FIVE_MOVE(className, ctorMove, opMove) \
         className(className &&) = ctorMove;                 \
         className& operator=(className &&) = opMove



//! Макрос для полного правила пяти
/*!
    UMBA_RULE_OF_FIVE(className, default|delete, default|delete, default|delete, default|delete, default|delete);
*/
#define  UMBA_RULE_OF_FIVE(className, ctorDef, ctorCopy, opCopy, ctorMove, opMove) \
         UMBA_RULE_OF_FIVE_DEF(className, ctorDef);                                \
         UMBA_RULE_OF_FIVE_COPY(className, ctorCopy, opCopy);                      \
         UMBA_RULE_OF_FIVE_MOVE(className, ctorMove, opMove)

