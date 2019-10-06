/*
Условие ИЗ№1:
Создать структуру для хранения информации о воздушных судах:
        марке (названии производителя),
        модели, назначении (грузовое, пассажирское и т.д.),
        численности экипажа и дальности полета.
Составить с ее использованием программу вывода информации обо
всех известных судах с группировкой по названию производителя
и сортировкой по возрастанию дальности полета.
*/

#include <malloc.h>
#include <stdbool.h>
#include <string.h>s
#include <stdio.h>

struct Airplane {
  char brand[20];
  char model[20];
  char appointment[20];
  int crew_number;
  int range;
};

bool is_less(const struct Airplane *l, const struct Airplane *r) {
  if (strcmp(l->brand, r->brand))
    return l->range < r->range;
  else
    return strcmp(l->brand, r->brand);
  /* if (strcmp(l.brand, r.brand) < 0)
  return true;
else
  return false;
*/
}

void merge_sort(struct Airplane *array, size_t size,
                bool(isLess)(const struct Airplane *,
                             const struct Airplane *)) {
  int mid = size / 2;
  if (size % 2 == 1)
    mid++;
  int h = 1;
  struct Airplane *c =
      (struct Airplane *)malloc(size * sizeof(struct Airplane));
  while (h < size) {
    int step = h;
    int i = 0;
    int j = mid;
    int k = 0;
    while (step <= mid) {
      while ((i < step) && (j < size) && (j < (mid + step))) {
        if (isLess(&array[i], &array[j])) {
          c[k] = array[i];
          i++;
          k++;
        } else {
          c[k] = array[j];
          j++;
          k++;
        }
      }
      while (i < step) {
        c[k] = array[i];
        i++;
        k++;
      }
      while ((j < (mid + step)) && (j < size)) {
        c[k] = array[j];
        j++;
        k++;
      }
      step = step + h;
    }
    h = h * 2;

    for (i = 0; i < size; i++)
      array[i] = c[i];
  }
  free(c);
}

int main() {
  printf("Hello, World!\n");
  int size;
  scanf("Write size: %d", &size);
  struct Airplane *ar =
      (struct Airplane *)malloc(size * sizeof(struct Airplane));

  for (size_t i = 0; i < size; i++) {
    scanf("%20s %20s %20s %d %d", ar[i].brand, &ar[i].model, &ar[i].appointment,
          &ar[i].crew_number, &ar[i].range);
  }

  merge_sort(ar, size, is_less);

  for (size_t i = 0; i < size; i++) {
    printf("%s %s %s %d %d\n", ar[i].brand, ar[i].model, ar[i].appointment,
           ar[i].crew_number, ar[i].range);
  }

  return 0;
}