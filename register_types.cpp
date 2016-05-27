#include "register_types.h"
#include "object_type_db.h"
#include "oamlGodotModule.h"

void register_oamlGodotModule_types() {
	ObjectTypeDB::register_type<oamlGodotModule>();
}

void unregister_oamlGodotModule_types() {
	//nothing to do here
}
