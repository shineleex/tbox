/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author      ruki
 * @file        static_fixed_pool_old.h
 * @ingroup     memory
 *
 */
#ifndef TB_MEMORY_STATIC_FIXED_POOL_OLD_H
#define TB_MEMORY_STATIC_FIXED_POOL_OLD_H

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_enter__

/* //////////////////////////////////////////////////////////////////////////////////////
 * types
 */

/*! the static fixed pool ref type
 *
 * <pre>
 * |---------|-----------------|-----------------------------------------------|
 *    head          used                            data     
 * </pre>
 */
typedef struct{}*           tb_static_fixed_pool_old_ref_t;

/* //////////////////////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! init pool
 *
 * @param data              the data
 * @param size              the size
 * @param step              the step
 * @param align             the align
 *
 * @return                  the pool handle
 */
tb_static_fixed_pool_old_ref_t  tb_static_fixed_pool_old_init(tb_byte_t* data, tb_size_t size, tb_size_t step, tb_size_t align);

/*! exit pool
 *
 * @param handle            the pool handle
 */
tb_void_t                   tb_static_fixed_pool_old_exit(tb_static_fixed_pool_old_ref_t pool);

/*! the pool item count
 *
 * @param handle            the pool handle
 *
 * @return                  the item count
 */
tb_size_t                   tb_static_fixed_pool_old_size(tb_static_fixed_pool_old_ref_t pool);

/*! clear pool
 *
 * @param handle            the pool handle
 */
tb_void_t                   tb_static_fixed_pool_old_clear(tb_static_fixed_pool_old_ref_t pool);

/*! malloc pool data
 *
 * @param handle            the pool handle
 * 
 * @return                  the data pointer
 */
tb_pointer_t                tb_static_fixed_pool_old_malloc(tb_static_fixed_pool_old_ref_t pool);

/*! malloc pool data and clear it
 *
 * @param handle            the pool handle
 *
 * @return                  the data pointer
 */
tb_pointer_t                tb_static_fixed_pool_old_malloc0(tb_static_fixed_pool_old_ref_t pool);

/*! duplicate pool data 
 *
 * @param handle            the pool handle
 * @param data              the data pointer
 *
 * @return                  the duplicated data pointer
 */
tb_pointer_t                tb_static_fixed_pool_old_memdup(tb_static_fixed_pool_old_ref_t pool, tb_cpointer_t data);

/*! free pool data
 *
 * @param handle            the pool handle
 * @param data              the pool item data
 *
 * @return                  tb_true or tb_false
 */
tb_bool_t                   tb_static_fixed_pool_old_free(tb_static_fixed_pool_old_ref_t pool, tb_pointer_t data);

/*! walk pool item
 *
 * @code
 * tb_bool_t tb_static_fixed_pool_old_item_func(tb_pointer_t item, tb_cpointer_t priv)
 * {
 *      // ok or break
 *      return tb_true;
 * }
 * @endcode
 *
 * @param handle            the pool handle
 * @param func              the walk func
 * @param priv              the walk data
 *
 */
tb_void_t                   tb_static_fixed_pool_old_walk(tb_static_fixed_pool_old_ref_t pool, tb_bool_t (*func)(tb_pointer_t , tb_cpointer_t ), tb_cpointer_t priv);

#ifdef __tb_debug__
/*! dump pool
 *
 * @param handle            the pool handle
 */
tb_void_t                   tb_static_fixed_pool_old_dump(tb_static_fixed_pool_old_ref_t pool);
#endif

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_leave__

#endif