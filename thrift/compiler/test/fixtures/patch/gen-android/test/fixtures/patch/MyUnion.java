/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package test.fixtures.patch;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.BitSet;
import java.util.Arrays;
import com.facebook.thrift.*;
import com.facebook.thrift.annotations.*;
import com.facebook.thrift.async.*;
import com.facebook.thrift.meta_data.*;
import com.facebook.thrift.server.*;
import com.facebook.thrift.transport.*;
import com.facebook.thrift.protocol.*;

@SuppressWarnings({ "unused", "serial", "unchecked" })
public class MyUnion extends TUnion<MyUnion> {
  private static final TStruct STRUCT_DESC = new TStruct("MyUnion");
  private static final TField OPTION1_FIELD_DESC = new TField("option1", TType.STRING, (short)1);
  private static final TField OPTION2_FIELD_DESC = new TField("option2", TType.I32, (short)2);

  public static final int OPTION1 = 1;
  public static final int OPTION2 = 2;

  public static final Map<Integer, FieldMetaData> metaDataMap = new HashMap<>();

  public MyUnion() {
    super();
  }

  public MyUnion(int setField, Object __value) {
    super(setField, __value);
  }

  public MyUnion(MyUnion other) {
    super(other);
  }

  public MyUnion deepCopy() {
    return new MyUnion(this);
  }

  public static MyUnion option1(String __value) {
    MyUnion x = new MyUnion();
    x.setOption1(__value);
    return x;
  }

  public static MyUnion option2(Integer __value) {
    MyUnion x = new MyUnion();
    x.setOption2(__value);
    return x;
  }


  @Override
  protected Object readValue(TProtocol iprot, TField __field) throws TException {
    switch (__field.id) {
      case OPTION1:
        if (__field.type == OPTION1_FIELD_DESC.type) {
          String option1;
          option1 = iprot.readString();
          return option1;
        }
        break;
      case OPTION2:
        if (__field.type == OPTION2_FIELD_DESC.type) {
          Integer option2;
          option2 = iprot.readI32();
          return option2;
        }
        break;
    }
    TProtocolUtil.skip(iprot, __field.type);
    return null;
  }

  @Override
  protected void writeValue(TProtocol oprot, short setField, Object __value) throws TException {
    switch (setField) {
      case OPTION1:
        String option1 = (String)getFieldValue();
        oprot.writeString(option1);
        return;
      case OPTION2:
        Integer option2 = (Integer)getFieldValue();
        oprot.writeI32(option2);
        return;
      default:
        throw new IllegalStateException("Cannot write union with unknown field " + setField);
    }
  }

  @Override
  protected TField getFieldDesc(int setField) {
    switch (setField) {
      case OPTION1:
        return OPTION1_FIELD_DESC;
      case OPTION2:
        return OPTION2_FIELD_DESC;
      default:
        throw new IllegalArgumentException("Unknown field id " + setField);
    }
  }

  @Override
  protected TStruct getStructDesc() {
    return STRUCT_DESC;
  }

  @Override
  protected Map<Integer, FieldMetaData> getMetaDataMap() { return metaDataMap; }

  private Object __getValue(int expectedFieldId) {
    if (getSetField() == expectedFieldId) {
      return getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field '" + getFieldDesc(expectedFieldId).name + "' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  private void __setValue(int fieldId, Object __value) {
    if (__value == null) throw new NullPointerException();
    setField_ = fieldId;
    value_ = __value;
  }

  public String getOption1() {
    return (String) __getValue(OPTION1);
  }

  public void setOption1(String __value) {
    __setValue(OPTION1, __value);
  }

  public Integer getOption2() {
    return (Integer) __getValue(OPTION2);
  }

  public void setOption2(Integer __value) {
    __setValue(OPTION2, __value);
  }

  public boolean equals(Object other) {
    if (other instanceof MyUnion) {
      return equals((MyUnion)other);
    } else {
      return false;
    }
  }

  public boolean equals(MyUnion other) {
    return equalsNobinaryImpl(other);
  }


  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {getSetField(), getFieldValue()});
  }

}
