#include<stdio.h>
#include<stdlib.h>

struct node {
    int co;
    int exp;
    struct node *link;
}*head1 = NULL, *head2 = NULL, *head3 = NULL;

void createTerm(int poly, int co, int exp)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    if(temp != NULL)
    {
        temp->co = co;
        temp->exp = exp;
        temp->link = NULL;

        if(poly == 1)
        {
            if(head1 == NULL)
                head1 = temp;
            else
            {
                struct node *p;
                p = head1;
                while(p->link != NULL)
                    p = p->link;
                p->link = temp;
            }
        }

        else if(poly == 2)
        {
            if(head2 == NULL)
                head2 = temp;
            else
            {
                struct node *p;
                p = head2;
                while(p->link != NULL)
                    p = p->link;
                p->link = temp;
            }
        }

        else if(poly == 3)
        {
            if(head3 == NULL)
                head3 = temp;
            else
            {
                struct node *p;
                p = head3;
                while(p->link != NULL)
                    p = p->link;
                p->link = temp;
            }
        }
    }
}

void addPolynomial()
{
    struct node *p1 = head1;
    struct node *p2 = head2;

    while(p1 != NULL || p2 != NULL)
    {
        if(p1 == NULL)
        {
            createTerm(3, p2->co, p2->exp);
            p2 = p2->link;
        }

        else if(p2 == NULL)
        {
            createTerm(3, p1->co, p1->exp);
            p1 = p1->link;
        }

        else if(p1->exp > p2->exp)
        {
            createTerm(3, p1->co, p1->exp);
            p1 = p1->link;
        }

        else if(p1->exp == p2->exp)
        {
            createTerm(3, p1->co + p2->co, p1->exp);
            p1 = p1->link;
            p2 = p2->link;
        }

        else if(p2->exp > p1->exp)
        {
            createTerm(3, p2->co, p2->exp);
            p2 = p2->link;
        }
    }
}

void display(int poly)
{
    struct node *p;

    switch(poly)
    {
        case 1: p = head1;
            break;
        case 2: p = head2;
            break;
        case 3: p = head3;
            break;
    }
        while(p != NULL)
        {
            if(p->co != 0)
            {
                if(p->exp == 1 && p->co == 1)
                    printf("x");

                else if(p->exp == 1)
                    printf("%dx", p->co);

                else if(p->exp == 0)
                    printf("%d", p->co);

                else if(p->co == 1)
                    printf("x^%d", p->exp);

                else
                    printf("%dx^%d", p->co, p->exp);

                if(p->link != NULL)
                    printf(" + ");
            }
            p = p->link;
        }
        printf("\n");
}

void sortPolynomial()
{
    struct node *p, *i, *j;
    int tempco, tempexp;

    for(i = head1; i != NULL; i = i->link)
    {
        p = i;
        for(j = i; j != NULL; j = j->link)
        {
            if(p->exp < j->exp)
                p = j;
        }
        tempco = p->co;
        tempexp = p->exp;
        p->co = i->co;
        p->exp = i->exp;
        i->co = tempco;
        i->exp = tempexp;
    }

    for(i = head2; i != NULL; i = i->link)
    {
        p = i;
        for(j = i; j != NULL; j = j->link)
        {
            if(p->exp < j->exp)
                p = j;
        }
        tempco = p->co;
        tempexp = p->exp;
        p->co = i->co;
        p->exp = i->exp;
        i->co = tempco;
        i->exp = tempexp;
    }
}

void main()
{
    int n1, n2, i, co, exp;

    printf("Enter no of terms in 1st Polynomial: ");
    scanf("%d", &n1);
    for(i = 0; i != n1; i++)
    {
        printf("Enter coefficient & exponent: ");
        scanf("%d %d", &co, &exp);
        createTerm(1, co, exp);
    }

    printf("Enter no of terms in 2nd Polynomial: ");
    scanf("%d", &n2);
    for(i = 0; i != n2; i++)
    {
        printf("Enter coefficient & exponent: ");
        scanf("%d %d", &co, &exp);
        createTerm(2, co, exp);
    }
    sortPolynomial();
    display(1);
    display(2);
    printf("\nAdding Polynomials.\n");
    addPolynomial();
    display(3);
}
