#include "ejdb.h"
#include <locale.h>


int main() {

    setlocale(LC_ALL, "en_US.UTF-8");
    
    int _db = ordo_db_init("addressbook");

    if (_db < 0) return -1;

    int _col = ordo_db_coll_bin(_db, "contacts");

   // ordo_db_add_json(_db, _col, "{\"hello\":\"Паситесь мирные народы\"}");

    char * dest_data;

    //ordo_db_get_all_from_coll(_db, _col, &dest_data);

    //ordo_db_query_coll(_db, _col, "{\"hello\":{\"$begin\":\"Па\"}}", &dest_data);

    ordo_get_by_id(_db, _col, "55e1ee3363969e4e00000000", &dest_data);

    fprintf(stderr, "%s\n", dest_data);

    ordo_db_close_by_index(_db);

    return 0;
}
