#pragma once
#include <limits>
#include <iostream>
#include <cstdint>

namespace nttl {

//
// A numeric T clamped on [VMin,VMax] w/ explicit conversion to
// wider numeric types.  
//
template<typename T, T VMin, T VMax>
class clamped_value {
public:
	static_assert(VMin<=VMax);
	static_assert((std::numeric_limits<T>::min()<=VMin
			&& std::numeric_limits<T>::max()>=VMax),
		"[VMin,VMax] exceeds the range of the underlying type");
	using value_type = T;
	static const T min_val = VMin;
	static const T max_val = VMax;

	template <typename From>
	static constexpr bool can_safely_construct_from() {
		return (std::is_convertible<From,value_type>::value
			&& (std::numeric_limits<From>::min()>=VMin)
			&& (std::numeric_limits<From>::max()<=VMax));
	};
	template <typename To>
	static constexpr bool can_safely_convert_to() {
		return (std::is_convertible<value_type,To>::value
			&& (std::numeric_limits<To>::min()<=VMin)
			&& (std::numeric_limits<To>::max()>=VMax));
	};

	explicit clamped_value()=default;

	template <typename From>
	constexpr explicit clamped_value(const From& val) {
		if (can_safely_construct_from<From>()) {
			this->val_= static_cast<value_type>(val);
		} else {
			if (val < VMin) {
				this->val_= VMin;
			} else if (val > VMax) {
				this->val_= VMax;
			} else {
				this->val_= static_cast<T>(val);
			}
		}
	};

	constexpr value_type value() const {
		return this->val_;
	};

	// Explicit conversion only to types capable of holding the full range
	// of allowed values.
	template<typename To, 
		typename Dummy = typename std::enable_if<clamped_value::can_safely_convert_to<To>(),bool>::type
	>
	explicit constexpr operator To() const {
		return static_cast<To>(this->val_);
	};
	// Implicit conversion to value_type
	constexpr operator value_type() const {
		return this->val_;
	};


	bool operator==(const clamped_value& rhs) const {
		return this->val_ == rhs.val_;
	};
	bool operator!=(const clamped_value& rhs) const {
		return !(*this == rhs);
	};
	bool operator<(const clamped_value& rhs) const {
		return this->val_ < rhs.val_;
	};
	bool operator>(const clamped_value& rhs) const {
		return this->val_ > rhs.val_;
	};
	bool operator<=(const clamped_value& rhs) const {
		return this->val_ <= rhs.val_;
	};
	bool operator>=(const clamped_value& rhs) const {
		return this->val_ >= rhs.val_;
	};

	clamped_value operator+(const clamped_value& rhs) const {
		return clamped_value(this->val_ + rhs.val_);
	};
	clamped_value operator-(const clamped_value& rhs) const {
		return clamped_value(this->val_ - rhs.val_);
	};
	clamped_value& operator+=(const clamped_value& rhs) {
		*this = clamped_value(this->val_ + rhs.val_);
		return *this;
	};
	clamped_value& operator-=(const clamped_value& rhs) {
		*this = clamped_value(this->val_ - rhs.val_);
		return *this;
	};
	clamped_value& operator++() {  // pre
		*this = clamped_value(++(this->val_));
		return *this;
	};
	clamped_value operator++(int) {  // post
		auto temp = this->val_;
		*this = clamped_value((this->val_)++);
		return clamped_value(temp);
	};
	clamped_value& operator--() {  // pre
		*this = clamped_value(--(this->val_));
		return *this;
	};
	clamped_value operator--(int) {  // post
		auto temp = this->val_;
		*this = clamped_value((this->val_)--);
		return clamped_value(temp);
	};
private:
	// Note that were this to be left unitialized, the invariant could 
	// be broken.  
	value_type val_ {VMin};  
};

template<typename T, T VMin, T VMax>
std::ostream& operator<<(std::ostream& os, const clamped_value<T,VMin,VMax>& cv) {
	os << static_cast<T>(cv);
	return os;
};


// Tests, demos
void inst_can_construct();
void static_casts_1();
void ctors_1();
void plus_minus_equals_1();
void compare_unlike_1();

}  // namespace nttl



