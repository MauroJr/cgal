// ======================================================================
//
// Copyright (c) 2003 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------
//
// release       : 
// release_date  : 
//
// file          : include/CGAL/Apollonius_graph_euclidean_traits_2.h
// package       : Apollonius_graph_2
// source        : $RCSfile$
// revision      : $Revision$
// revision_date : $Date$
// author(s)     : Menelaos Karavelas <mkaravel@cse.nd.edu>
//
// coordinator   :
//
// ======================================================================



#ifndef CGAL_APOLLONIUS_GRAPH_EUCLIDEAN_TRAITS_2_H
#define CGAL_APOLLONIUS_GRAPH_EUCLIDEAN_TRAITS_2_H

#include <CGAL/Triangulation_euclidean_traits_2.h>
#include <CGAL/Parabola_segment_2.h>
#include <CGAL/Hyperbola_2.h>
#include <CGAL/Hyperbola_segment_2.h>
#include <CGAL/Hyperbola_ray_2.h>

#include <CGAL/Filtered_kernel.h>
#include <CGAL/Filtered_predicate.h>

#ifndef CGAL_REP_CLASS_DEFINED
#error  no representation class defined
#endif  // CGAL_REP_CLASS_DEFINED

#if defined CGAL_CARTESIAN_H || defined CGAL_SIMPLE_CARTESIAN_H
#include <CGAL/predicates/Apollonius_graph_ftC2.h>
#include <CGAL/Apollonius_graph_constructions_ftC2.h>
#endif

#if defined CGAL_HOMOGENEOUS_H || defined CGAL_SIMPLE_HOMOGENEOUS_H
#include <CGAL/predicates/Apollonius_graph_rtH2.h>
#include <CGAL/Apollonius_graph_constructions_rtH2.h>
#endif


#include <CGAL/Kernel_traits.h>
#include <CGAL/Number_type_traits.h>

#include <CGAL/Apollonius_graph_kernel_wrapper_2.h>

#ifdef CGAL_CFG_NO_AUTOMATIC_TEMPLATE_INCLUSION
#include <CGAL/Apollonius_graph_euclidean_traits_2.C>
#endif

#include <CGAL/Apollonius_graph_constructions_C2.h>

#define KEEP_MOST_TYPES_IN_TRAITS 0


CGAL_BEGIN_NAMESPACE

//-----------------------------------------------------------------------
// the Traits class
//-----------------------------------------------------------------------
template < class Rep, class MTag = Ring_tag >
class Apollonius_graph_euclidean_traits_2
{
public:
  //-----------------------------------------------------------------------
  //                  TYPE DEFINITIONS
  //-----------------------------------------------------------------------

  // BASIC TYPES
  //------------
private:  
  typedef Apollonius_graph_kernel_wrapper_2<Rep>        Kernel;
  typedef Apollonius_graph_euclidean_traits_2<Rep,MTag> Self;

public:
  typedef Rep                                           R;
  typedef MTag                                          Method_tag;
  typedef typename Kernel::Point_2                      Point_2;
  typedef typename Kernel::Site_2                       Site_2;

  typedef typename Kernel::Line_2                       Line_2;
  typedef typename Kernel::Ray_2                        Ray_2;
  typedef typename Rep::Segment_2                       Segment_2;

  typedef typename Kernel::Object_2                     Object_2;
  typedef typename Kernel::FT                           FT;
  typedef typename Kernel::RT                           RT;

private:
  typedef typename Site_2::FT                           Weight;

public:
#if KEEP_MOST_TYPES_IN_TRAITS
  typedef CGAL::Parabola_segment_2<Point_2,Weight,Line_2>
  /*                                                 */ Parabola_segment_2;
  typedef CGAL::Hyperbola_2<Self>                       Hyperbola_2;
  typedef CGAL::Hyperbola_ray_2<Self>                   Hyperbola_ray_2;
  typedef CGAL::Hyperbola_segment_2<Self>
  /*                                                 */ Hyperbola_segment_2;
#endif

public:
  // OBJECT CONSTRUCTION & ASSIGNMENT
  //---------------------------------
  typedef typename Kernel::Construct_object_2     Construct_object_2;
  typedef typename Kernel::Assign_2               Assign_2;

  // CONSTRUCTIONS
  //--------------
  // vertex and dual site
  typedef CGAL::Construct_Apollonius_vertex_2<Kernel>
  /*                                      */ Construct_Apollonius_vertex_2;
  typedef CGAL::Construct_Apollonius_site_2<Kernel>
  /*                                        */ Construct_Apollonius_site_2;


#if KEEP_MOST_TYPES_IN_TRAITS
  // bisectors and subsets
  typedef CGAL::Construct_Apollonius_bisector_2<Self>
  /*                                    */ Construct_Apollonius_bisector_2;
  typedef CGAL::Construct_Apollonius_bisector_ray_2<Self>
  /*                                */ Construct_Apollonius_bisector_ray_2;
  typedef CGAL::Construct_Apollonius_bisector_segment_2<Self>
  /*                            */ Construct_Apollonius_bisector_segment_2;

  // primal edges
  typedef CGAL::Construct_Apollonius_primal_ray_2<Self> 
  /*                                   */ Construct_Apollonius_primal_ray_2;
  typedef CGAL::Construct_Apollonius_primal_segment_2<Self>
  /*                               */ Construct_Apollonius_primal_segment_2;
#endif

  // PREDICATES
  //-----------
  typedef typename Kernel::Compare_x_2                  Compare_x_2;
  typedef typename Kernel::Compare_y_2                  Compare_y_2;
  typedef CGAL::Compare_weight_2<Kernel>                Compare_weight_2;
  typedef typename Kernel::Orientation_2                Orientation_2;
  typedef CGAL::Is_hidden_2<Kernel,MTag>                Is_hidden_2;
  typedef CGAL::Oriented_side_of_bisector_2<Kernel,MTag> 
  /*                                          */ Oriented_side_of_bisector_2;
  typedef CGAL::Vertex_conflict_2<Kernel,MTag >            Vertex_conflict_2;
  typedef CGAL::Finite_edge_interior_conflict_2<Kernel,MTag >
  /*                                      */ Finite_edge_interior_conflict_2;
  typedef CGAL::Infinite_edge_interior_conflict_2<Kernel,MTag>
  /*                                    */ Infinite_edge_interior_conflict_2;
  typedef CGAL::Is_degenerate_edge_2<Kernel,MTag>       Is_degenerate_edge_2;


public:
  //-----------------------------------------------------------------------
  //                  ACCESS TO OBJECTS
  //-----------------------------------------------------------------------

  // OBJECT CONSTRUCTION & ASSIGNMENT
  Assign_2
  assign_2_object() const {
    return Assign_2();
  }

  Construct_object_2
  construct_object_2_object() const { 
    return Construct_object_2();
  }


  // CONSTRUCTIONS
  //--------------
  Construct_Apollonius_vertex_2
  construct_Apollonius_vertex_2_object() const { 
    return Construct_Apollonius_vertex_2();
  }

  Construct_Apollonius_site_2
  construct_Apollonius_site_2_object() const {
    return Construct_Apollonius_site_2();
  }

#if KEEP_MOST_TYPES_IN_TRAITS
  Construct_Apollonius_bisector_2
  construct_Apollonius_bisector_2_object() const {
    return Construct_Apollonius_bisector_2();
  }

  Construct_Apollonius_bisector_ray_2
  construct_Apollonius_bisector_ray_2_object() const {
    return Construct_Apollonius_bisector_ray_2();
  }

  Construct_Apollonius_bisector_segment_2
  construct_Apollonius_bisector_segment_2_object() const { 
    return Construct_Apollonius_bisector_segment_2(); 
  }

  Construct_Apollonius_primal_ray_2
  construct_Apollonius_primal_ray_2_object() const {
    return Construct_Apollonius_primal_ray_2(); 
  }

  Construct_Apollonius_primal_segment_2
  construct_Apollonius_primal_segment_2_object() const { 
    return Construct_Apollonius_primal_segment_2();
  }
#endif

  // PREDICATES
  //-----------
  Compare_x_2
  compare_x_2_object() const {
    return Compare_x_2();
  }

  Compare_y_2
  compare_y_2_object() const {
    return Compare_y_2();
  }

  Compare_weight_2
  compare_weight_2_object() const {
    return Compare_weight_2();
  }

  Orientation_2
  orientation_2_object() const {
    return Orientation_2();
  }

  Is_hidden_2
  is_hidden_2_object() const {
    return Is_hidden_2();
  }

  Oriented_side_of_bisector_2
  oriented_side_of_bisector_2_object() const {
    return Oriented_side_of_bisector_2();
  }

  Vertex_conflict_2
  vertex_conflict_2_object() const {
    return Vertex_conflict_2();
  }

  Finite_edge_interior_conflict_2
  finite_edge_interior_conflict_2_object() const {
    return Finite_edge_interior_conflict_2();
  }

  Infinite_edge_interior_conflict_2
  infinite_edge_interior_conflict_2_object() const {
    return Infinite_edge_interior_conflict_2();
  }

  Is_degenerate_edge_2
  is_degenerate_edge_2_object() const {
    return Is_degenerate_edge_2();
  }

};


#if 0
// I AM REMOVING THE FILTERED KERNEL STUFF SO THAT I DON'T GET ANY
// PROBLEMS WITH PARTIAL SPECIALIZATION AND ALSO BECAUSE THE CURRENT
// DEFINITION OF FILTERED KERNEL DOES NOT SUPPORT MORE THAN ONE
// TEMPLATE ARGUMENT

// CHANGE THE TEMPLATE NAMES SO THAT THERE IS NO UNDERSCROEE IN THE
// BEGINNING

//-----------------------------------------------------------------------
// the Traits class for a filtered kernel
//-----------------------------------------------------------------------
template< class MTag, class _CK, class _EK, class _FK,
  class _C2E, class _C2F >
class Apollonius_graph_euclidean_traits_2<
Filtered_kernel<_CK,_EK,_FK,_C2E,_C2F>, MTag>
{
private:
  typedef Apollonius_graph_kernel_wrapper_2<_CK>  CK;
  typedef Apollonius_graph_kernel_wrapper_2<_EK>  EK;
  typedef Apollonius_graph_kernel_wrapper_2<_FK>  FK;
  typedef Extended_cartesian_converter<_C2E>  C2E;
  typedef Extended_cartesian_converter<_C2F>  C2F;

public:
  //-----------------------------------------------------------------------
  //                  TYPE DEFINITIONS
  //-----------------------------------------------------------------------

  // BASIC TYPES
  //------------
  typedef Kernel_wrapper_2< Filtered_kernel<CK,EK,FK,C2E,C2F> >  Kernel;
  typedef Kernel                                         Rep;
  typedef MTag                                           Method_tag;
  typedef typename Kernel::RT                            Weight;
  typedef typename Kernel::Point_2                       Point_2;
  typedef typename Kernel::Site_2                        Site_2;
  //
  typedef typename Kernel::Object_2                      Object_2;
  typedef typename Kernel::Line_2                        Line_2;
  typedef typename Kernel::Ray_2                         Ray_2;
  typedef typename Kernel::Segment_2                     Segment_2;
  typedef CGAL::Parabola_segment_2<Point_2,Weight,Line_2>
  /*                                                  */ Parabola_segment_2;
  typedef CGAL::Hyperbola_2<Point_2,Weight>         Hyperbola_2;
  typedef CGAL::Hyperbola_ray_2<Point_2,Weight>     Hyperbola_ray_2;
  typedef CGAL::Hyperbola_segment_2<Point_2,Weight> Hyperbola_segment_2;

public:
  // CONSTRUCTIONS
  //--------------
  // vertex and dual site
  typedef CGAL::Construct_Apollonius_vertex_2<Kernel>
  /*                                      */ Construct_Apollonius_vertex_2;
  typedef CGAL::Construct_Apollonius_site_2<Kernel>
  /*                                        */ Construct_Apollonius_site_2;

  // bisectors and subsets
  typedef CGAL::Construct_Apollonius_bisector_2<Kernel>
  /*                                    */ Construct_Apollonius_bisector_2;
  typedef CGAL::Construct_Apollonius_bisector_ray_2<Kernel>
  /*                                */ Construct_Apollonius_bisector_ray_2;
  typedef CGAL::Construct_Apollonius_bisector_segment_2<Kernel>
  /*                            */ Construct_Apollonius_bisector_segment_2;

  // primal edges
  typedef CGAL::Construct_Apollonius_primal_ray_2<Kernel>
  /*                                   */ Construct_Apollonius_primal_ray_2;
  typedef CGAL::Construct_Apollonius_primal_segment_2<Kernel>
  /*                               */ Construct_Apollonius_primal_segment_2;


private:
  // Predicates for the construction kernel
  typedef CGAL::Compare_weight_2<CK>                   CK_compare_weight_2;
  typedef CGAL::Is_hidden_2<CK,MTag>                   CK_is_hidden_2;
  typedef CGAL::Oriented_side_of_bisector_2<CK,MTag> 
  /*                                      */ CK_oriented_side_of_bisector_2;
  typedef CGAL::Vertex_conflict_2<CK,MTag >            CK_vertex_conflict_2;
  typedef CGAL::Finite_edge_interior_conflict_2<CK,MTag >
  /*                                  */ CK_finite_edge_interior_conflict_2;
  typedef CGAL::Infinite_edge_interior_conflict_2<CK,MTag>
  /*                                */ CK_infinite_edge_interior_conflict_2;
  typedef CGAL::Is_degenerate_edge_2<CK,MTag>       CK_is_degenerate_edge_2;

  // Predicates for the exact kernel
  typedef CGAL::Compare_weight_2<EK>                   EK_compare_weight_2;
  typedef CGAL::Is_hidden_2<EK,MTag>                   EK_is_hidden_2;
  typedef CGAL::Oriented_side_of_bisector_2<EK,MTag> 
  /*                                      */ EK_oriented_side_of_bisector_2;
  typedef CGAL::Vertex_conflict_2<EK,MTag >            EK_vertex_conflict_2;
  typedef CGAL::Finite_edge_interior_conflict_2<EK,MTag >
  /*                                  */ EK_finite_edge_interior_conflict_2;
  typedef CGAL::Infinite_edge_interior_conflict_2<EK,MTag>
  /*                                */ EK_infinite_edge_interior_conflict_2;
  typedef CGAL::Is_degenerate_edge_2<EK,MTag>       EK_is_degenerate_edge_2;

  // Predicates for the filtering kernel
  typedef CGAL::Compare_weight_2<FK>                   FK_compare_weight_2;
  typedef CGAL::Is_hidden_2<FK,MTag>                   FK_is_hidden_2;
  typedef CGAL::Oriented_side_of_bisector_2<FK,MTag> 
  /*                                      */ FK_oriented_side_of_bisector_2;
  typedef CGAL::Vertex_conflict_2<FK,MTag >            FK_vertex_conflict_2;
  typedef CGAL::Finite_edge_interior_conflict_2<FK,MTag >
  /*                                  */ FK_finite_edge_interior_conflict_2;
  typedef CGAL::Infinite_edge_interior_conflict_2<FK,MTag>
  /*                                */ FK_infinite_edge_interior_conflict_2;
  typedef CGAL::Is_degenerate_edge_2<FK,MTag>       FK_is_degenerate_edge_2;

public:
  // PREDICATES
  //-----------
  typedef typename Kernel::Compare_x_2                   Compare_x_2;
  typedef typename Kernel::Compare_y_2                   Compare_y_2;
  typedef Filtered_predicate<EK_compare_weight_2,
    FK_compare_weight_2,C2E,C2F> Compare_weight_2;
  typedef typename Kernel::Orientation_2                 Orientation_2;
  typedef Filtered_predicate<EK_is_hidden_2,
    FK_is_hidden_2,C2E,C2F> Is_hidden_2;
  typedef Filtered_predicate<EK_oriented_side_of_bisector_2,
    FK_oriented_side_of_bisector_2,C2E,C2F> Oriented_side_of_bisector_2;
  typedef Filtered_predicate<EK_vertex_conflict_2,
    FK_vertex_conflict_2,C2E,C2F> Vertex_conflict_2;
  typedef Filtered_predicate<EK_finite_edge_interior_conflict_2,
    FK_finite_edge_interior_conflict_2,C2E,C2F>
  Finite_edge_interior_conflict_2;
  typedef Filtered_predicate<EK_infinite_edge_interior_conflict_2,
    FK_infinite_edge_interior_conflict_2,C2E,C2F>
  Infinite_edge_interior_conflict_2;
  typedef Filtered_predicate<EK_is_degenerate_edge_2,
    FK_is_degenerate_edge_2,C2E,C2F> Is_degenerate_edge_2;

public:
  //-----------------------------------------------------------------------
  //                  ACCESS TO OBJECTS
  //-----------------------------------------------------------------------

  // CONSTRUCTIONS
  //--------------
  Construct_Apollonius_vertex_2
  construct_Apollonius_vertex_2_object() const { 
    return Construct_Apollonius_vertex_2();
  }

  Construct_Apollonius_site_2
  construct_Apollonius_site_2_object() const {
    return Construct_Apollonius_site_2();
  }

  Construct_Apollonius_bisector_2
  construct_Apollonius_bisector_2_object() const {
    return Construct_Apollonius_bisector_2();
  }

  Construct_Apollonius_bisector_ray_2
  construct_Apollonius_bisector_ray_2_object() const {
    return Construct_Apollonius_bisector_ray_2();
  }

  Construct_Apollonius_bisector_segment_2
  construct_Apollonius_bisector_segment_2_object() const { 
    return Construct_Apollonius_bisector_segment_2(); 
  }

  Construct_Apollonius_primal_ray_2
  construct_Apollonius_primal_ray_2_object() const {
    return Construct_Apollonius_primal_ray_2(); 
  }

  Construct_Apollonius_primal_segment_2
  construct_Apollonius_primal_segment_2_object() const { 
    return Construct_Apollonius_primal_segment_2();
  }

  // PREDICATES
  //-----------
  Compare_x_2
  compare_x_2_object() const {
    return Compare_x_2();
  }

  Compare_y_2
  compare_y_2_object() const {
    return Compare_y_2();
  }

  Compare_weight_2
  compare_weight_2_object() const {
    return Compare_weight_2();
  }

  Orientation_2
  orientation_2_object() const {
    return Orientation_2();
  }

  Is_hidden_2
  is_hidden_2_object() const {
    return Is_hidden_2();
  }

  Oriented_side_of_bisector_2
  oriented_side_of_bisector_2_object() const {
    return Oriented_side_of_bisector_2();
  }

  Vertex_conflict_2
  vertex_conflict_2_object() const {
    return Vertex_conflict_2();
  }

  Finite_edge_interior_conflict_2
  finite_edge_interior_conflict_2_object() const {
    return Finite_edge_interior_conflict_2();
  }

  Infinite_edge_interior_conflict_2
  infinite_edge_interior_conflict_2_object() const {
    return Infinite_edge_interior_conflict_2();
  }

  Is_degenerate_edge_2
  is_degenerate_edge_2_object() const {
    return Is_degenerate_edge_2();
  }

};
#endif


CGAL_END_NAMESPACE

#endif // CGAL_APOLLONIUS_GRAPH_EUCLIDEAN_TRAITS_2_H
