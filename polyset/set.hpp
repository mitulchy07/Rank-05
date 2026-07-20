/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 03:56:29 by mwallis           #+#    #+#             */
/*   Updated: 2025/11/22 03:56:29 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "searchable_bag.hpp"

class set
{
private:
    searchable_bag *_bag;

public:
    set(searchable_bag &bag);
    set(const set &other);
    set &operator=(const set &other);
    ~set();

    void insert(int value);
    void insert(int *array, int size);
    void print() const;
    void clear();
    bool has(int value) const;

    searchable_bag &get_bag();
    const searchable_bag &get_bag() const;
};

#endif