//
// Created by Alexandr on 08.06.2015.
//

#ifndef TP_MATRIX_H
#define TP_MATRIX_H

#include <stdio.h>
#include <c++/iostream>
#include <c++/fstream>
#include <minwindef.h>

using namespace std;

struct Elem
{
    int val;
    Elem* next;
    Elem* down;
};

struct matrix
{
    Elem* beg;
    Elem* cur;
    BYTE n;
    BYTE m;
};

bool EmptyCheck(matrix *a)
{
    if (a->beg == nullptr)
        return true;
    else
        return false;
}

void goto_line(matrix *a, BYTE i)  // ������� � i-��� ������
{
    BYTE k;
    if(i == 0)
        cout <<"Error"<<endl;
    if(i > a->n)
        cout << "Matrix has lower lines"<<endl;
    else
    {
        a->cur = a->beg;
        k = 1;
        while (k != i)
        {
            a->cur = a->cur->down;
            k++;
        }
    }
}

void goto_column(matrix *a, BYTE j)  // ������� � j-���� �������
{
    BYTE k;
    if(j > a->n)
        cout << "Matrix has lower column"<<endl;
    else
    {
        a->cur = a->beg;
        k = 1;
        while (k != j)
        {
            a->cur = (*a->cur).next;
            k++;
        }
    }
}

void goto_nextLine(matrix a)  // ������� ������� ��������� ��-� � �������
{
    if (a.cur->down != nullptr)
    {
        a.cur = a.cur->down;
    }
}

void goto_nextColumn(matrix *a)  // ������� ������� ��������� ��-� � ������
{
    if((*a->cur).next != nullptr)
    {
        a->cur = (*a->cur).next;
    }
}

void AddColumn(matrix *a)  // ��������� �������
{
    Elem *elem =new Elem();
    Elem *pointer;

    goto_column(a, a->m);
    a->m ++;

    elem->next = nullptr;
    elem->down = nullptr;
    (*a->cur).next = elem;
    pointer = a->cur;

    for (BYTE i = 2; i <a->n ; i++)
    {
        a->cur = elem;
        elem->down = nullptr;
        a->cur->down = elem;
        pointer = pointer->down;
        elem->next = nullptr;
        pointer->next = elem;
    }
}

void AddLine(matrix *a)  // ���������� ������
{
    Elem *elem = new Elem();
    Elem *pointer;

    goto_line(a,a->n);
    a->n++;

    elem->next = nullptr;
    elem->down = nullptr;
    (*a->cur).down = elem;
    pointer = a->cur;

    for (BYTE i = 2; i <a->m ; i++)
    {
        a->cur = elem;
        elem->next = nullptr;
        a->cur->next = elem;
        pointer = pointer->next;
        elem->down = nullptr;
        pointer->down = elem;
    }
}

void MakeEmptyMatrix(matrix *a, BYTE n, BYTE m)  // �������� ������ ������� nxm
{
    //(*a->beg).next = nullptr;
   // (*a->beg).down = nullptr;
    a->n = 1;
    a->m = 1;
    for(BYTE i =1; i<n;i++ )
    {
        AddLine(a);
    }
    for (BYTE j = 1; j<m; j++)
    {
        AddColumn(a);
    }
}

void ChangeValue(matrix *a, int t) // ��������� �������� ��-��
{
    (*a->cur).val = t;
}

int getValue(matrix a)  // ������ �������� ��-��
{
    return a.cur->val;
}

void DeleteColomn(matrix *a)   // �������� ���������� �������
{
    Elem *elem1, *elem2;

    if(a->m == 1)
    {
        a->cur = a->beg;
        a->m = 0;
        while (a->cur != nullptr)
        {
            a->beg = (*a->beg).down;
            delete a->cur;
            a->cur = a->beg;
        }
    }
    else
    {
        goto_column(a, a->m - (BYTE) 1);
        a->m--;
        elem1 = a->cur;
        a->cur = a->cur->next;
        while (a->cur != nullptr)
        {
            elem2 = a->cur;
            a->cur = a->cur->down;
            delete elem2;
        }
        a->cur = elem1;
        while (a->cur != nullptr)
        {
            (*a->cur).next = nullptr;
            a->cur = (*a->cur).down;
        }
    }
}

void DeleteLine(matrix *a)   // �������� ��������� ������
{
    Elem *elem1, *elem2;

    if(a->n == 1)
    {
        a->cur = a->beg;
        a->n = 0;
        while (a->cur != nullptr)
        {
            a->beg = (*a->beg).next;
            delete a->cur;
            a->cur = a->beg;
        }
    }
    else
    {
        goto_line(a, a->n - (BYTE) 1);
        a->n--;
        elem1 = a->cur;
        a->cur = (*a->cur).down;
        while (a->cur != nullptr)
        {
            elem2 = a->cur;
            a->cur = a->cur->next;
            delete elem2;
        }
        a->cur = elem1;
        while (a->cur != nullptr)
        {
            (*a->cur).down = nullptr;
            a->cur = (*a->cur).next;
        }
    }
}

void addLog(string s, matrix *a, ofstream& output_file )  // ����� � ��� ����
{
    BYTE i,j;
    ofstream logFile;

    logFile << "Matrix size is : "<< a->n<< "x" << a->m << endl;

    if (EmptyCheck(a))
        logFile << "Matrix is empty"<<endl;
    else
    {
        for (i = 1; i <a->n ; i++)
        {
            goto_line(a,i);
            logFile << (*a->cur).val;
        }
        logFile << endl;
    }
    logFile.close();
}
#endif //TP_MATRIX_H
