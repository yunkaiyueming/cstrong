#include <stdio.h>
#include <stdlib.h>

//用hash+链表方式实现map
typedef struct st_entry
{
    void *key;
    void *val;
    struct st_entry *next; // /
} Entry;

typedef struct
{
    int size;                              //
    int table_size;                        //
    Entry *table_array;                    //
    unsigned int (*hashcode)(void *key);   //结构体函数指针hashcode
    int (*equals)(void *key1, void *key2); //结构体函数指针equals
} SHashMap;

extern unsigned int hashcode_int(void *key)
{
    int k = *(int *)key;
    return k < 0 ? 131 - k : 131 + k;
}

extern int equals_int(void *key1, void *key2)
{
    int k1 = *(int *)key1;
    int k2 = *(int *)key2;
    return k1 == k2 ? 1 : 0;
}

extern unsigned int hashcode_str(void *key)
{
    unsigned int hashcode = 0;
    char *str = (char *)key;
    while (*str)
    {
        hashcode = (*str++) + (hashcode << 6) + (hashcode << 16) - hashcode;
    }
    hashcode &= 0x7FFFFFFF;
    return hashcode;
}

extern int equals_str(void *key1, void *key2)
{
    char *k1 = (char *)key1;
    char *k2 = (char *)key2;
    while (1)
    {
        if (*k1 != *k2)
        {
            return 0;
        }
        if (*k1)
        {
            break;
        }
    }
    return 1;
}

extern SHashMap *shashmap_init(unsigned int (*hashcode)(void *key), int (*equals)(void *key1, void *key2))
{
    SHashMap *map = malloc(sizeof(SHashMap));
    if (map == NULL)
    {
        perror("malloc shashmap error");
        exit(0);
    }
    map->hashcode = hashcode;
    map->equals = equals;
    map->size = 0;
    map->table_size = 131;
    map->table_array = calloc(map->table_size, sizeof(Entry));//连续分配table_size个 sizeof(Entry)大小的内存空间&初始化
    if (map->table_array == NULL)
    {
        perror("calloc shashmap table array error");
        exit(0);
    }
    return map;
}

extern void shashmap_put(SHashMap *map, void *key, void *val)
{
    int index = (*(map->hashcode))(key) % map->table_size;

    Entry *table = map->table_array + index;
    Entry *entry = malloc(sizeof(Entry));
    if (entry == NULL)
    {
        perror("malloc entry error");
        exit(0);
    }
    entry->key = key;
    entry->val = val;
    entry->next = table->next;
    table->next = entry;
}

extern void *shashmap_get(SHashMap *map, void *key)
{
    int index = (*(map->hashcode))(key) % map->table_size;
    Entry *entry = (map->table_array + index)->next;
    while (entry != NULL)
    {
        //int v = ((*map->equals)(key, entry->key));
        if ((*map->equals)(key, entry->key))
        {
            return entry->val;
        }
        entry = entry->next;
    }
    return NULL;
}

extern void shashmap_free(SHashMap *map)
{
    int i;
    for (i = 0; i < map->table_size; i++)
    {
        Entry *entry = (map->table_array + i)->next;
        while (entry != NULL)
        {
            Entry *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(map->table_array);
    free(map);
}

void shashmap_foreach(SHashMap *map)
{
    int i;
    for (i = 0; i < map->table_size; i++)
    {
        Entry *entry = (map->table_array + i)->next;
        while (entry != NULL)
        {
            printf("%s:%s \n", entry->key, entry->val);
            entry = entry->next;
        }
    }
}

extern void shashmap_remove(SHashMap *map, void *key)
{
    int index = (*(map->hashcode))(key) % map->table_size;
    Entry *table = map->table_array + index;
    Entry *entry = (map->table_array + index)->next;
    while (entry != NULL)
    {
        //int v = ((*map->equals)(key, entry->key));
        if ((*map->equals)(key, entry->key))
        {
            table->next = entry->next;
            //Entry *tmp = table->next;
            //return entry->val;
        }
        entry = entry->next;
    }
}

void main()
{
    //按照字符串hash 和比较
    SHashMap *map = shashmap_init(hashcode_str, equals_int);
    //SHashMap *map = shashmap_init(hashcode_int, equals_int);
    shashmap_put(map, "age", "10");
    shashmap_put(map, "name", "zanshang");
    shashmap_put(map, "score", "1000");
    shashmap_put(map, "school", "xxschool");
    printf("遍历得到 \n");
    shashmap_foreach(map);

    //按照 int hash 和比较
    SHashMap *map2 = shashmap_init(hashcode_str, equals_int);
    shashmap_put(map2, "1", "100");
    shashmap_put(map2, "2", "200");
    shashmap_put(map2, "3", "300");
    shashmap_put(map2, "4", "400");
    printf("遍历得到 \n");
    shashmap_foreach(map2);

    //按照 int hash 和比较
    SHashMap *map3 = shashmap_init(hashcode_int, equals_int);
    shashmap_put(map3, "1", "100");
    shashmap_put(map3, "2", "200");
    shashmap_put(map3, "3", "300");
    shashmap_put(map3, "4", "400");
    printf("遍历得到 \n");
    shashmap_foreach(map3);

    char *v = shashmap_get(map, "name");
    printf("%s \n", v);

    char *v2 = shashmap_get(map2, "2");
    printf("%s \n", v2);

    char *v3 = shashmap_get(map3, "3");
    printf("%s \n", v3);

    printf("移除字符串后遍历得到 \n");
    shashmap_remove(map3, "2");
    shashmap_foreach(map3);

    printf("移除字符串score后遍历得到 \n");
    shashmap_remove(map, "score");
    shashmap_foreach(map);
}