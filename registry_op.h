#pragma once

#include <Windows.h>

namespace metax {
class RegistryOp {
 public:
  // 创建注册表
  static void Create();
  // 查找注册表
  static BOOL Read();
  // 更新注册表
  static void Update();
  // 删除注册表
  static void Delete();
};
}  // namespace metax