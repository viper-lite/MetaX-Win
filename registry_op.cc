#include "registry_op.h"

#include <atlstr.h>
#include <tchar.h>

// 参考 https://blog.csdn.net/tojohnonly/article/details/78329470
namespace metax {
BOOL RegistryOp::Create() {
  BOOL ret = FALSE;
  HKEY hKEY;
  HKEY hTEMPKEY;
  CString strName = _T("China");
  DWORD nLength = (strName.GetLength() + 1) * sizeof(TCHAR);
  LPBYTE lpbName = new BYTE[nLength];
  memcpy(lpbName, (void*)(LPCTSTR)strName, nLength);
  LPCTSTR strPath = _T("Directory\\Background\\shell\\MetaX");
  // 打开 HKEY
  if (ERROR_SUCCESS ==
      ::RegOpenKeyEx(HKEY_CLASSES_ROOT, strPath, 0, KEY_READ, &hKEY)) {
    // 在当前键下创建子键
    if (ERROR_SUCCESS == ::RegCreateKey(hKEY, _T("VIPER"), &hTEMPKEY)) {
      // 给子键设置值
      if (ERROR_SUCCESS ==
          ::RegSetValueEx(hTEMPKEY, _T("Name"), 0, REG_SZ, lpbName, nLength)) {
        ret = TRUE;
      }
      // 关闭 HKEY
      ::RegCloseKey(hTEMPKEY);
    }
    // 关闭 HKEY
    ::RegCloseKey(hKEY);
  }
  return ret;
}
BOOL RegistryOp::Read() {
  BOOL ret = FALSE;
  HKEY hKEY;
  LPCTSTR strPath = _T("Directory\\Background\\shell\\MetaX");
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