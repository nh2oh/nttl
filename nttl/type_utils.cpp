#include "type_utils.h"



int is_subject_to_integral_promotion_tests() {
	//----------------------------------------------------------------------------
	// Types smaller than int are subject to int promotion...
	static_assert(is_subject_to_integral_promotion<unsigned char>::value);
	static_assert(is_subject_to_integral_promotion<char>::value);
	static_assert(is_subject_to_integral_promotion<unsigned short>::value);
	static_assert(is_subject_to_integral_promotion<short>::value);
	if constexpr (sizeof(int) >= sizeof(int8_t)) {
		static_assert(is_subject_to_integral_promotion<uint8_t>::value);
		static_assert(is_subject_to_integral_promotion<int8_t>::value);
	}
	if constexpr (sizeof(int) >= sizeof(int16_t)) {
		static_assert(is_subject_to_integral_promotion<uint16_t>::value);
		static_assert(is_subject_to_integral_promotion<int16_t>::value);
	}

	//----------------------------------------------------------------------------
	// Types w/ rank >= that of int are not...
	static_assert(!is_subject_to_integral_promotion<unsigned int>::value);
	static_assert(!is_subject_to_integral_promotion<int>::value);
	if constexpr (sizeof(int) <= sizeof(int32_t)) {
		static_assert(!is_subject_to_integral_promotion<uint32_t>::value);
		static_assert(!is_subject_to_integral_promotion<int32_t>::value);
	}
	if constexpr (sizeof(int) <= sizeof(int64_t)) {
		static_assert(!is_subject_to_integral_promotion<uint64_t>::value);
		static_assert(!is_subject_to_integral_promotion<int64_t>::value);
	}
	if constexpr (sizeof(int) <= sizeof(long)) {
		static_assert(!is_subject_to_integral_promotion<unsigned long>::value);
		static_assert(!is_subject_to_integral_promotion<long>::value);
	}

	static_assert(!is_subject_to_integral_promotion<float>::value);
	static_assert(!is_subject_to_integral_promotion<double>::value);

	return 0;
}


int undergoes_integral_promotion_to_tests() {
	//----------------------------------------------------------------------------
	// Types smaller than int are subject to int promotion...
	static_assert(std::is_same<undergoes_integral_promotion_to<unsigned char>::type,int>::value);
	static_assert(std::is_same<undergoes_integral_promotion_to<char>::type,int>::value);
	static_assert(std::is_same<undergoes_integral_promotion_to<unsigned short>::type,int>::value);
	static_assert(std::is_same<undergoes_integral_promotion_to<short>::type,int>::value);

	if constexpr (is_subject_to_integral_promotion<int8_t>::value) {
		static_assert(std::is_same<undergoes_integral_promotion_to<uint8_t>::type,int>::value);
		static_assert(std::is_same<undergoes_integral_promotion_to<int8_t>::type,int>::value);
	}
	if constexpr (is_subject_to_integral_promotion<int16_t>::value) {
		static_assert(std::is_same<undergoes_integral_promotion_to<int16_t>::type,int>::value);
		static_assert(std::is_same<undergoes_integral_promotion_to<uint16_t>::type,int>::value);
	}

	return 0;
}



