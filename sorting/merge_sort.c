void merge(int A[], int p, int q, int r)
{
    /* Create L ← A[p..q] and M ← A[q+1..r] */
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = A[q + 1 + j];

    /* Maintain current index of sub-arrays and main array */
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    /* Until we reach either end of either L or M, pick larger among elements L and M and place them in the correct position at A[p..r] */
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            A[k] = L[i]; //arr[k]
            i++;
        }
        else
        {
            A[k] = M[j]; //arr[k]
            j++;
        }
        k++;
    }

    /* When we run out of elements in either L or M, pick up the remaining elements and put in A[p..r] */
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = M[j];
        j++;
        k++;
    }
}