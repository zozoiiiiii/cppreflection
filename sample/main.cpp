#include "test.h"


int main()
{
    // test1
    {
      MetaClass* pMetaClass_Vec2Test = Point::MetaClassInstance();
      MetaField* pMetaField = pMetaClass_Vec2Test->fields["x"];

      Point vt;
      vt.x = 1.0f;
      vt.y = 2.0f;

      float* xx = (float*)pMetaField->Get(&vt);
    }

    // test2
    {
      MetaClass* pMetaClass_Test = Test::MetaClassInstance();
      MetaField* pMetaField = pMetaClass_Test->fields["position"];

      // field
      Test tt;
      Point* aa = (Point*)pMetaField->Get(&tt);
      Point bb;
      bb.x=1.0f;
      pMetaField->Set(&tt, &bb);

      MetaMethod* pMetaMethod = pMetaClass_Test->methods["Set"];
      float result;

      // method
      Point cc;
      Point* pCC = &cc;
      pCC->x = 1.1f;

      void* parameters[1];
      parameters[0]=&pCC;
      pMetaMethod->Invoke(&result, pMetaClass_Test, parameters);
    }
}
