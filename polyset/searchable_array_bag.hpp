/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:52:46 by mwallis           #+#    #+#             */
/*   Updated: 2025/11/21 21:52:46 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_ARRAY_BAG_HPP
# define SEARCHABLE_ARRAY_BAG_HPP

# include "array_bag.hpp"
# include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
public:
    searchable_array_bag();
    searchable_array_bag(const searchable_array_bag &other);
    searchable_array_bag &operator=(const searchable_array_bag &other);
    ~searchable_array_bag();

    bool has(int value) const;
};

#endif