/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 21:38:47 by drissi            #+#    #+#             */
/*   Updated: 2021/02/06 21:47:59 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(){
    char *test;
    test = malloc(4);
    test[0] = '1';
    test[1] = '2';
    test[2] = '3';
    test[3] = '\0';
    char *grr;
    grr = test;
    free(grr);
    printf("%s\n", test);
}