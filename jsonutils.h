#ifndef JSONUTILS_H
#define JSONUTILS_H
#include "JSON Library/json.hpp"
#include "table.h"
using json = nlohmann::json;

namespace JSONutils {
json tableToJson(Table table);
Table jsonToTable(json inputJson);
}

#endif // JSONUTILS_H
