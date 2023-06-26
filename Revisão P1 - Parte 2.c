#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ordenação por inserção
void Inserção (int n, int v[]) {
int i, j, x;
for (j = 1; /*A*/ j < n; j++) {
x = v[j];
for (i = j-1; i >= 0 && v[i] > x; i--)
v[i+1] = v[i];
v[i+1] = x;
}
}

// Seleção

void Seleção (int n, int v[]) {
int i, j, min, x;
for (i = 0; /*A*/ i < n-1; i++) {
min = i;
for (j = i+1; j < n; j++)
if (v[j] < v[min]) min = j;
x = v[i]; v[i] = v[min]; v[min] = x;
}
}

// Mergesort

void Intercala (int p, int q, int r, int v[]) {
int i, j, k, *w;
w = malloc ((r-p) * sizeof (int));
i = p; j = q; k = 0;
while (i < q && j < r) {
if (v[i] <= v[j]) w[k++] = v[i++];
else w[k++] = v[j++];
}
while (i < q) w[k++] = v[i++];
while (j < r) w[k++] = v[j++];
for (i = p; i < r; i++) v[i] = w[i-p];
free (w);
}

void Mergesort (int p, int r, int v[]) {
if (p < r - 1) {
int q = (p + r)/2;
Mergesort (p, q, v);
Mergesort (q, r, v);
Intercala (p, q, r, v);
}
}

void MergesortI (int n, int v[]) {
int p, r, b = 1;
while (b < n) {
p = 0;
while (p + b < n) {
r = p + 2*b;
if (r > n) r = n;
Intercala (p, p + b, r, v);
p = p + 2*b;
}
b = 2*b;
}
}

// Heapsort

void InsereEmHeap (int m, int v[]) {
int f = m+1;
while /*X*/ (f > 1 && v[f /2] < v[f ]) {
int t = v[f /2]; v[f /2] = v[f ]; v[f ] = t;
f = f /2;
}
}

void SacodeHeap (int m, int v[]) {
int t, f = 2;
while /*X*/ (f <= m) {
if (f < m && v[f ] < v[f +1]) ++f ;
if (v[f /2] >= v[f ]) break;
t = v[f /2]; v[f /2] = v[f ]; v[f ] = t;
f *= 2;
}
}

void Heapsort (int n, int v[]) {
int m;
for (m = 1; m < n; m++)
InsereEmHeap (m, v);
for (m = n; /*X*/ m > 1; m--) {
int t = v[1]; v[1] = v[m]; v[m] = t;
SacodeHeap (m-1, v);
}
}

// Quicksort

int Separa (int p, int r, int v[]) {
int c, j, k, t;
c = v[r]; j = p;
for (k = p; /*A*/ k < r; k++)
if (v[k] <= c) {
t = v[j], v[j] = v[k], v[k] = t;
j++;
}
v[r] = v[j], v[j] = c;
return j;
}

void Quicksort (int p, int r, int v[]) {
int j;
if (p < r) {
j = Separa (p, r, v);
Quicksort (p, j - 1, v);
Quicksort (j + 1, r, v);
}
}

//Cuida primeiro do menor dos subvetores
void QuickSortP (int p, int r, int v[]) {
int j;
while (p < r) {
j = Separa (p, r, v);
if (j - p < r - j) {
QuickSortP (p, j - 1, v);
p = j + 1;
} else {
QuickSortP (j + 1, r, v);
r = j - 1;
}
}
}

int main(){

  return 0;
}
