#include <stdio.h>
#include <stdlib.h>

int main() {
 
    int n, q, max_value;
    int n_case = 1;
    while(1) {
        scanf("%d %d",&n, &q);
        if (n == 0 && q == 0) break;

        printf("CASE# %d:\n", n_case);
        n_case++;

        int * m_array = malloc(n*sizeof(int));
        max_value = 0;
        for (int i=0;i<n;i++){
            scanf("%d",&m_array[i]);
            if (m_array[i] > max_value) {
                max_value = m_array[i];
            }
        }

        int * count_array = malloc((max_value+1)*sizeof(int));
        int * exist_array = malloc((max_value+1)*sizeof(int));
        for (int i=0;i<=max_value;i++){
            count_array[i] = 0;
            exist_array[i] = 0;
        }
        for (int i=0;i<n;i++){
            count_array[m_array[i]]++;
            exist_array[m_array[i]]++;
        }
        for (int i=1;i<=max_value;i++){
            count_array[i] = count_array[i] + count_array[i-1];
        }
        for (int i=n-1; i>=0;i--){
            count_array[m_array[i]]--;
        }

        int consult;
        for (int i=0;i<q;i++){
            scanf("%d",&consult);

            if ((consult > max_value)||(exist_array[consult] == 0)) {
                printf("%d not found\n", consult);
            } else {
                printf("%d found at %d\n", consult, count_array[consult]+1);
            }
        }

        free(m_array);
        free(count_array);
        free(exist_array);

    }
 
    return 0;
}