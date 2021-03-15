#include <stdio.h>
#if 0
#include <unistd.h>
#else
typedef unsigned int uid_t;
typedef unsigned int gid_t;
#endif

enum wbcIdType {
       WBC_ID_TYPE_NOT_SPECIFIED,
       WBC_ID_TYPE_UID,
       WBC_ID_TYPE_GID,
       WBC_ID_TYPE_BOTH
};

union wbcUnixId2Container {
       uid_t uid;
       gid_t gid;
};

struct wbcUnixId {
       enum wbcIdType type;
       union wbcUnixId2Container id;
};

static void make_error(void)
{
       struct wbcUnixId wbc_ids[10];
#ifdef TRIGGER
       struct wbcUnixId *wbc_ids_ptr = wbc_ids;
#endif
       unsigned int i, wbc_ids_size;
       wbc_ids_size = 10;
       for (i=0; i < wbc_ids_size; i++) {
               wbc_ids[i].type = WBC_ID_TYPE_NOT_SPECIFIED;
               wbc_ids[i].id.gid = (unsigned int)-1;
       }
#if TRIGGER
       for (i=0; i < wbc_ids_size; i++) {
               wbc_ids_ptr[i].type = WBC_ID_TYPE_NOT_SPECIFIED;
               wbc_ids_ptr[i].id.gid = (unsigned int)-1;
       }
#endif
       if (wbc_ids[0].type == WBC_ID_TYPE_NOT_SPECIFIED) {
	 printf("Foo\n");
       }
}

int main(int c, char** argv)
{
       make_error();
       return 0;
}
