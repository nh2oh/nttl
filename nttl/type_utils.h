#pragma once
#include <limits>
#include <type_traits>
#include <cstdint>

template<typename T1, typename T2>
struct has_different_signedness {
	static constexpr bool value = (
		(std::is_signed<T1>::value && std::is_unsigned<T2>::value) 
		|| (std::is_signed<T2>::value && std::is_unsigned<T1>::value));
};

template<typename T>
struct is_subject_to_integral_promotion {
	static constexpr bool value = (
		std::is_fundamental<T>::value
		&& std::is_integral<T>::value 
		&& !std::is_same<T,int>::value 
		&& std::is_same<int,decltype(T()+T())>::value);
};

// The type should always be int...
template<typename T>
struct undergoes_integral_promotion_to {
	using type = 
		typename std::enable_if<
			is_subject_to_integral_promotion<T>::value,decltype(T()+T())>::type;
};

int is_subject_to_integral_promotion_tests();
int undergoes_integral_promotion_to_tests();

