
#ifndef CPPCMS_BOOST_MPL_O1_SIZE_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_O1_SIZE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: O1_size.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/O1_size_fwd.hpp>
#include <cppcms_boost/mpl/sequence_tag.hpp>
#include <cppcms_boost/mpl/aux_/O1_size_impl.hpp>
#include <cppcms_boost/mpl/aux_/na_spec.hpp>
#include <cppcms_boost/mpl/aux_/lambda_support.hpp>

namespace cppcms_boost { namespace mpl {

// returns sequence size if it's an O(1) operation; otherwise returns -1
template<
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    >
struct O1_size
    : O1_size_impl< typename sequence_tag<Sequence>::type >
        ::template apply< Sequence >
{
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1, O1_size, (Sequence))
};

CPPCMS_BOOST_MPL_AUX_NA_SPEC(1, O1_size)

}}

#endif // BOOST_MPL_O1_SIZE_HPP_INCLUDED
