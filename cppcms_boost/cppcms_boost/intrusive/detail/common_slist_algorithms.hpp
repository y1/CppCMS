/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga  2007-2009
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef CPPCMS_BOOST_INTRUSIVE_COMMON_SLIST_ALGORITHMS_HPP
#define CPPCMS_BOOST_INTRUSIVE_COMMON_SLIST_ALGORITHMS_HPP

#include <cppcms_boost/intrusive/detail/config_begin.hpp>
#include <cppcms_boost/intrusive/intrusive_fwd.hpp>
#include <cppcms_boost/intrusive/detail/assert.hpp>
#include <cstddef>

namespace cppcms_boost {
namespace intrusive {
namespace detail {

template<class NodeTraits>
class common_slist_algorithms
{
   public:
   typedef typename NodeTraits::node            node;
   typedef typename NodeTraits::node_ptr        node_ptr;
   typedef typename NodeTraits::const_node_ptr  const_node_ptr;
   typedef NodeTraits                           node_traits;

   static node_ptr get_previous_node(node_ptr prev_init_node, node_ptr this_node)
   {
      node_ptr p = prev_init_node;
      for( node_ptr p_next
         ; this_node != (p_next = NodeTraits::get_next(p))
         ; p = p_next){
         //Logic error: possible use of linear lists with
         //operations only permitted with lists
         CPPCMS_BOOST_INTRUSIVE_INVARIANT_ASSERT(p);
      }
      return p;
   }

   static void init_header(node_ptr this_node)  
   {  NodeTraits::set_next(this_node, this_node);  }  

   static void init(node_ptr this_node)  
   {  NodeTraits::set_next(this_node, node_ptr(0));  }  

   static bool unique(const_node_ptr this_node)
   {
      node_ptr next = NodeTraits::get_next(this_node);
      return !next || next == this_node;
   }

   static bool inited(const_node_ptr this_node)  
   {  return !NodeTraits::get_next(this_node); }

   static void unlink_after(node_ptr prev_node)
   {
      node_ptr this_node(NodeTraits::get_next(prev_node));
      NodeTraits::set_next(prev_node, NodeTraits::get_next(this_node));
   }

   static void unlink_after(node_ptr prev_node, node_ptr last_node)
   {  NodeTraits::set_next(prev_node, last_node);  }

   static void link_after(node_ptr prev_node, node_ptr this_node)
   {
      NodeTraits::set_next(this_node, NodeTraits::get_next(prev_node));
      NodeTraits::set_next(prev_node, this_node);
   }

   static void incorporate_after(node_ptr bp, node_ptr b, node_ptr be)
   {
      node_ptr p(NodeTraits::get_next(bp));
      NodeTraits::set_next(bp, b);
      NodeTraits::set_next(be, p);
   }
   
   static void transfer_after(node_ptr bp, node_ptr bb, node_ptr be)
   {
      if (bp != bb && bp != be && bb != be) {
         node_ptr next_b = NodeTraits::get_next(bb);
         node_ptr next_e = NodeTraits::get_next(be);
         node_ptr next_p = NodeTraits::get_next(bp);
         NodeTraits::set_next(bb, next_e);
         NodeTraits::set_next(be, next_p);
         NodeTraits::set_next(bp, next_b);
      }
   }
};

} //namespace detail
} //namespace intrusive 
} //namespace boost 

#include <cppcms_boost/intrusive/detail/config_end.hpp>

#endif //BOOST_INTRUSIVE_COMMON_SLIST_ALGORITHMS_HPP
