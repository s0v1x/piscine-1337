/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 22:27:52 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 22:32:15 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>




typedef struct sudoku sudoku;
struct sudoku {
    int value;
    sudoku *next;
    char is_const;
    int i;
    int j;
};
typedef struct arbre arbre;
struct arbre{
    sudoku* debut;
    arbre* next;
};

arbre* create_arbre(sudoku *l)
{
    arbre* element = (arbre*)malloc(sizeof(arbre));
    element->debut=l;
    element->next=NULL;
    return element;
}

void add_arbre(arbre **head,sudoku *l)
{
    arbre *elem=create_arbre(l);
    if(*head == NULL)
    {
        *head =  elem;
        return ;
    }
    arbre *tmp = *head;
    *head = elem;
    elem->next = tmp;
}


sudoku *create_posibilite(int value,int i,int j)
{
    sudoku* element = (sudoku)malloc(sizeof(sudoku));
    element->value = value;
    element->next = NULL;
    element->is_const = 'n';
    element->i=i;
    element->j=j;
    return (element);
}

void    add_posibilite(sudoku **head, int value,int i,int j)
{
    sudoku *elem = create_posibilite(value,i,j);
    
    if (*head == NULL)
    {
        *head = elem;
        return ;
    }
    sudoku *tmp = *head;
    *head = elem;
    elem->next = tmp;
}

void    supp_posibilite(sudoku **head, int value)
{
    sudoku *tmp = *head;
    if(*head==NULL) return;
    if (tmp->value == value) 
    {
        *head = tmp->next;
        free(tmp);
        return ;
    }
    if(tmp->next==NULL) return;
    while (tmp->next->next && tmp->next->value !=value)
        tmp = tmp->next;
    if (tmp->next->value == value)
    {
        sudoku *dp = tmp->next;
        tmp->next = tmp->next->next;
        free(dp);
    }
}

void    my_putnbr(int n)
{
    if (n < 0)
    {
        my_putchar('-');
        n = -n;
    }
    if (n > 9)
    {
        my_putnbr(n / 10);
        my_putnbr(n % 10);
    }
    else
        my_putchar(n + '0');
}


void affpos(sudoku *l)
{
    while(l)
    {
        my_putnbr(l->value);
        l=l->next;
    }
}

void viderList(sudoku **l)
{
    if((*l)==NULL)
    {free(l);return ;}
    sudoku* tmp = *l;
    while(l)
    {
        tmp = *l;
        *l=(*l)->next;
        free(tmp);
    }
    
}

int count_list(sudoku* l)
{
    int c=0;
    while(l)
    {
        c++;
        l=l->next;
    }
    return (c);
    
}

void suppArbre(arbre* a,int value)
{
    sudoku* tmp;
    while(a)
    {
        supp_posibilite(&(a->debut),value);
        a=a->next;
        
    }
}

sudoku  Union(arbre *a)
{
    sudoku l1={0,NULL,'n',-1,-1};
    sudoku* l2;
    sudoku* l3;
    int cp;
    arbre* tmp=a;
    int trouve = 1;
    while(a)
    {
        l3=a->debut;
        trouve = 0;
        
        while(l3)
        {     tmp=a->next;
            trouve = 0;
            while(tmp)
            {
                l2=tmp->debut;
                while(l2)
                {
                    
                    if (l3->value == l2->value) {  trouve = 1;suppArbre(a,l2->value);break  ;}
                    l2=l2->next;
                }
                if(trouve == 1) break;
                tmp=tmp->next;
                
            }
            
            
            if(trouve == 0)
            {       l1=*l3;
                return l1;
            }
            
            l3=l3->next;
        }
        
        a=a->next;
        
    }
    return l1;
}

void affArbre(arbre* a)
{
    sudoku* tmp;
    while(a)
    {
        tmp = a->debut;
        affpos(tmp);
        a=a->next;
        
    }
}


/////////////fin list

int is_in_square(int t[9][9],int row, int col, int value)
{
    int i,j;
    i =0;
    while (i< 3)
    {    j =0;
        while( j< 3)
        {
            if (t[i+row][j+col] == value)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int is_in_row(int t[9][9], int row,int col, int value)
{
    int i;
    i = 0;
    while ( i< 9)
    {
        if (t[i][col] == value)
            return (1);
        i++;
    }
    return (0);
}

int is_in_col(int t[9][9], int row,int col, int value)
{
    int i;
    i = 0;
    while ( i< 9)
    {
        if (t[row][i] == value)
            return (1);
        i++;
    }
    return (0);
}
void    ft_putstr(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}




void    affichage(int t[9][9])
{
    int i;
    int j;
    i = 0;
    while (i < 9 )
    {
        j = 0;
        while (j< 9)
        {
            my_putchar(t[i][j]);
            j++;
        }
        write(1, "\n",1);
        i++;
    }
}

int reapeat(int t[9][9])
{
    int i;
    int j;
    i =0;
    while(i<9)
    {
        j =0;
        while(j<9)
        {
            if(t[i][j]==0)
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

arbre *remplir(int t[9][9], int si,int sj,int *cp,sudoku **debut)
{
    arbre* a=NULL;
    int i;
    int j;
    int k;
    i=si-3;
    while(i<si)
    {
        j=sj-3;
        while(j<sj)
        {
            if(t[i][j] == 0)
            {    k = 1;
                *cp = 0;
                *debut=NULL;
                while( k<= 9)
                {
                    if(!is_in_square(t,i-i%3,j-j%3,k))
                    {
                        if(!is_in_row(t,i,j,k))
                        {
                            if(!is_in_col(t,i,j,k))
                            {
                                add_posibilite(debut,k,i,j);
                                *cp = *cp + 1;
                                
                            }
                        }
                    }
                    k++;
                }
                
                add_arbre(&a,*debut);
                
            }
            j++;
            
        }
        i++;
    }
    return a;
}

void posi(int t[9][9])
{
    int i,j;
    int k;
    int si;
    int sj;
    int l;
    int c;
    int cp;
    sudoku* debut;
    arbre* a;
    
    while(reapeat(t)==1)
    {
        l=0;
        si=0;
        sj=0;
        debut=NULL;
        a=NULL;;

        
        while(l < 3)
        {
            c =0;
            si+=3;sj=0;
            while(c<3)
            {
                sj+=3;
                ///////
                a=remplir(t,si,sj,&cp,&debut);
                if(cp !=1)
                {
                    
                    sudoku x=Union(a);
                    if(x.value!=0)
                    {
                        t[x.i][x.j]=x.value;
                    }
                    
                }else if(cp == 1 && debut)
                {
                    sudoku x=*debut;
                    t[x.i][x.j]=x.value;
                }
                a=NULL;
                c++;
            }
            l++;
        }
        
    }
}


int main(int argc, char **argv)
{
    int Sudoku[9][9];
    int i,j;
    
    i = 1;
	j = 0;
	if (argc != 10)
		write(1, "\n", 1);
    while(i < 10)
    {
        j = 0;
        while(j < 9)
        {
            
            if(argv[i][j]!='.')
                Sudoku[i - 1][j]=(int)argv[i][j];
            else
                Sudoku[i][j]=0;
			j++;
        }
		i++;
    }
    
    
    posi(Sudoku);
    affichage(Sudoku);
    return 0;
}
