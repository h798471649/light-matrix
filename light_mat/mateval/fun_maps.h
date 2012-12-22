/**
 * @file fun_maps.h
 *
 * Functor maps
 * 
 * @author Dahua Lin 
 */

#ifdef _MSC_VER
#pragma once
#endif

#ifndef LIGHTMAT_FUN_MAPS_H_
#define LIGHTMAT_FUN_MAPS_H_

#include <light_mat/mateval/mateval_fwd.h>
#include <light_mat/math/math_functors.h>


#define LMAT_DEFINE_NATIVE_SUPPORT( Name, KindName ) \
	template<> struct has_native_support<Name##_, KindName##_t> { \
		static const bool value = math::has_##KindName##_##Name::value; };

#ifdef LMAT_HAS_AVX
#define LMAT_DEFINE_NATIVE_SUPPORTS( Name ) \
	LMAT_DEFINE_NATIVE_SUPPORT( Name, sse ) \
	LMAT_DEFINE_NATIVE_SUPPORT( Name, avx )
#else
#define LMAT_DEFINE_NATIVE_SUPPORTS( Name ) \
	LMAT_DEFINE_NATIVE_SUPPORT( Name, sse )
#endif


#define LMAT_DEFINE_GENERIC_FUNMAP_1( Name ) \
	template<typename T> \
	struct fun_map<Name##_, T> { \
		typedef math::Name##_fun<T> type; }; \
	LMAT_DEFINE_NATIVE_SUPPORTS( Name )


#define LMAT_DEFINE_GENERIC_FUNMAP_2( Name ) \
	template<typename T> \
	struct fun_map<Name##_, T, T> { \
		typedef math::Name##_fun<T> type; }; \
	LMAT_DEFINE_NATIVE_SUPPORTS( Name )

#define LMAT_DEFINE_REAL_FUNMAP_1( Name ) \
	template<> struct fun_map<Name##_, float> { \
		typedef math::Name##_fun<float> type; }; \
	template<> struct fun_map<Name##_, double> { \
		typedef math::Name##_fun<double> type; }; \
	LMAT_DEFINE_NATIVE_SUPPORTS( Name )

#define LMAT_DEFINE_REAL_FUNMAP_2( Name ) \
	template<> struct fun_map<Name##_, float, float> { \
		typedef math::Name##_fun<float> type; }; \
	template<> struct fun_map<Name##_, double, double> { \
		typedef math::Name##_fun<double> type; }; \
	LMAT_DEFINE_NATIVE_SUPPORTS( Name )


namespace lmat
{
	template<typename FTag, typename... T>
	struct fun_map;

	template<typename FTag, typename SKind>
	struct has_native_support;

	// arithmetics

	LMAT_DEFINE_GENERIC_FUNMAP_2( add )
	LMAT_DEFINE_GENERIC_FUNMAP_2( sub )
	LMAT_DEFINE_GENERIC_FUNMAP_2( mul )
	LMAT_DEFINE_GENERIC_FUNMAP_2( div )
	LMAT_DEFINE_GENERIC_FUNMAP_1( neg )

	LMAT_DEFINE_GENERIC_FUNMAP_1( abs )
	LMAT_DEFINE_GENERIC_FUNMAP_1( sqr )
	LMAT_DEFINE_GENERIC_FUNMAP_1( cube )

	LMAT_DEFINE_GENERIC_FUNMAP_2( max )
	LMAT_DEFINE_GENERIC_FUNMAP_2( min )

	// real math

	LMAT_DEFINE_REAL_FUNMAP_1( rcp )
	LMAT_DEFINE_REAL_FUNMAP_1( sqrt )
	LMAT_DEFINE_REAL_FUNMAP_1( rsqrt )
	LMAT_DEFINE_REAL_FUNMAP_2( pow )

	LMAT_DEFINE_REAL_FUNMAP_1( floor )
	LMAT_DEFINE_REAL_FUNMAP_1( ceil )

	LMAT_DEFINE_REAL_FUNMAP_1( exp )
	LMAT_DEFINE_REAL_FUNMAP_1( log )
	LMAT_DEFINE_REAL_FUNMAP_1( log10 )

	LMAT_DEFINE_REAL_FUNMAP_1( sin )
	LMAT_DEFINE_REAL_FUNMAP_1( cos )
	LMAT_DEFINE_REAL_FUNMAP_1( tan )

	LMAT_DEFINE_REAL_FUNMAP_1( asin )
	LMAT_DEFINE_REAL_FUNMAP_1( acos )
	LMAT_DEFINE_REAL_FUNMAP_1( atan )
	LMAT_DEFINE_REAL_FUNMAP_2( atan2 )

	LMAT_DEFINE_REAL_FUNMAP_1( sinh )
	LMAT_DEFINE_REAL_FUNMAP_1( cosh )
	LMAT_DEFINE_REAL_FUNMAP_1( tanh )

	// C++11 real math

#ifdef LMAT_HAS_CXX11_MATH

	LMAT_DEFINE_REAL_FUNMAP_1( cbrt )
	LMAT_DEFINE_REAL_FUNMAP_2( hypot )

	LMAT_DEFINE_REAL_FUNMAP_1( round )
	LMAT_DEFINE_REAL_FUNMAP_1( trunc )

	LMAT_DEFINE_REAL_FUNMAP_1( exp2 )
	LMAT_DEFINE_REAL_FUNMAP_1( log2 )
	LMAT_DEFINE_REAL_FUNMAP_1( expm1 )
	LMAT_DEFINE_REAL_FUNMAP_1( log1p )

	LMAT_DEFINE_REAL_FUNMAP_1( asinh )
	LMAT_DEFINE_REAL_FUNMAP_1( acosh )
	LMAT_DEFINE_REAL_FUNMAP_1( atanh )

	LMAT_DEFINE_REAL_FUNMAP_1( erf )
	LMAT_DEFINE_REAL_FUNMAP_1( erfc )

	LMAT_DEFINE_REAL_FUNMAP_1( lgamma )
	LMAT_DEFINE_REAL_FUNMAP_1( tgamma )

#endif

}

#endif 