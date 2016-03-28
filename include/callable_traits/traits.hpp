/*!
@file

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_TRAITS_HPP
#define CALLABLE_TRAITS_TRAITS_HPP


#include <callable_traits/generalized_class.hpp>
#include <callable_traits/disjunction.hpp>
#include <callable_traits/fwd/pmd_fwd.hpp>
#include <callable_traits/fwd/pmf_fwd.hpp>
#include <callable_traits/fwd/function_fwd.hpp>
#include <callable_traits/fwd/function_object_fwd.hpp>
#include <callable_traits/bind_expression_traits.hpp>
#include <callable_traits/shallow_decay.hpp>

#include <type_traits>

namespace callable_traits {

    namespace detail {

        template<typename T>
        using remove_reference_if_ptr = typename std::conditional<
            std::is_pointer<typename std::remove_reference<T>::type>::value,
            typename std::remove_reference<T>::type,
            T
        >::type;
        
        template<typename T>
        using traits = typename disjunction<
            bind_expression_traits<shallow_decay<T>>,
            function_object<generalized_class<T>>,
            function<remove_reference_if_ptr<T>>,
            pmf<shallow_decay<T>>,
            pmd<shallow_decay<T>>,
            function_object<generalized_class<T>>
        >::traits;
    }
}

#endif
