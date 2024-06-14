#include "registry_op.h"

#include <tchar.h>

namespace metax {
void RegistryOp::Create() {}
BOOL RegistryOp::Read() {
  BOOL ret = FALSE;
  HKEY hKEY;
  LPCTSTR strPath = _T("Directory\\Background\\shell\\WizTree");
  // 打开 HKEY
  if (ERROR_SUCCESS ==
      ::RegOpenKeyEx(HKEY_CLASSES_ROOT, strPath, 0, KEY_READ, &hKEY)) {
    char szValue[256] = {0};
    DWORD dwSize = sizeof(szValue);
    DWORD dwType = REG_SZ;
    // 查询 HKEY
    if (ERROR_SUCCESS == ::RegQueryValueEx(hKEY, _T("Icon"), 0, &dwType,
                                           (LPBYTE)&szValue, &dwSize)) {
      ret = TRUE;
    }
    // 关闭 HKEY
    ::RegCloseKey(hKEY);
  }
  return ret;
}
void RegistryOp::Update() {}
void RegistryOp::Delete() {}
}  // namespace metax