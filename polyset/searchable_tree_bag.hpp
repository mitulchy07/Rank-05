/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 01:45:59 by mwallis           #+#    #+#             */
/*   Updated: 2025/11/22 01:45:59 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

# include "tree_bag.hpp"
# include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
public:
    searchable_tree_bag();
    searchable_tree_bag(const searchable_tree_bag &other);
    searchable_tree_bag &operator=(const searchable_tree_bag &other);
    ~searchable_tree_bag();

    bool has(int value) const;
};

#endif