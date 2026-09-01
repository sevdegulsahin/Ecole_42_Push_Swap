/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 13:40:58 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/01 17:05:56 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_nodes(t_stack **src,t_stac **dest)
{
  t_stac *temp;
  if(!src || !dest)
    return;
temp=*src;
  if(temp->next==temp)
  {
    *src=NULL;
  }
  else
  {
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    *src=temp->next; 
  }
  
  if(*dest)
  {
    *dest=temp;
    temp->next=temp;
    temp -> prev=temp;
    
  }
  else
  {
   temp->next=*dst;
    temp->prev=(*dst)->prev;
    temp->prev->next=temp;
    (*dest)->prev=temp;
    *dst=temp;
    
  }
    
}