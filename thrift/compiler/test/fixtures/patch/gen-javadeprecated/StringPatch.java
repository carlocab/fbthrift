/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
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

@SuppressWarnings({ "unused", "serial" })
public class StringPatch implements TBase, java.io.Serializable, Cloneable, Comparable<StringPatch> {
  private static final TStruct STRUCT_DESC = new TStruct("StringPatch");
  private static final TField ASSIGN_FIELD_DESC = new TField("assign", TType.STRING, (short)1);
  private static final TField CLEAR_FIELD_DESC = new TField("clear", TType.BOOL, (short)2);
  private static final TField PREPEND_FIELD_DESC = new TField("prepend", TType.STRING, (short)4);
  private static final TField APPEND_FIELD_DESC = new TField("append", TType.STRING, (short)5);

  public String assign;
  public boolean clear;
  public String prepend;
  public String append;
  public static final int ASSIGN = 1;
  public static final int CLEAR = 2;
  public static final int PREPEND = 4;
  public static final int APPEND = 5;

  // isset id assignments
  private static final int __CLEAR_ISSET_ID = 0;
  private BitSet __isset_bit_vector = new BitSet(1);

  public static final Map<Integer, FieldMetaData> metaDataMap;

  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    tmpMetaDataMap.put(ASSIGN, new FieldMetaData("assign", TFieldRequirementType.OPTIONAL, 
        new FieldValueMetaData(TType.STRING)));
    tmpMetaDataMap.put(CLEAR, new FieldMetaData("clear", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.BOOL)));
    tmpMetaDataMap.put(PREPEND, new FieldMetaData("prepend", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    tmpMetaDataMap.put(APPEND, new FieldMetaData("append", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  static {
    FieldMetaData.addStructMetaDataMap(StringPatch.class, metaDataMap);
  }

  public StringPatch() {
  }

  public StringPatch(
      boolean clear,
      String prepend,
      String append) {
    this();
    this.clear = clear;
    setClearIsSet(true);
    this.prepend = prepend;
    this.append = append;
  }

  public StringPatch(
      String assign,
      boolean clear,
      String prepend,
      String append) {
    this();
    this.assign = assign;
    this.clear = clear;
    setClearIsSet(true);
    this.prepend = prepend;
    this.append = append;
  }

  public static class Builder {
    private String assign;
    private boolean clear;
    private String prepend;
    private String append;

    BitSet __optional_isset = new BitSet(1);

    public Builder() {
    }

    public Builder setAssign(final String assign) {
      this.assign = assign;
      return this;
    }

    public Builder setClear(final boolean clear) {
      this.clear = clear;
      __optional_isset.set(__CLEAR_ISSET_ID, true);
      return this;
    }

    public Builder setPrepend(final String prepend) {
      this.prepend = prepend;
      return this;
    }

    public Builder setAppend(final String append) {
      this.append = append;
      return this;
    }

    public StringPatch build() {
      StringPatch result = new StringPatch();
      result.setAssign(this.assign);
      if (__optional_isset.get(__CLEAR_ISSET_ID)) {
        result.setClear(this.clear);
      }
      result.setPrepend(this.prepend);
      result.setAppend(this.append);
      return result;
    }
  }

  public static Builder builder() {
    return new Builder();
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public StringPatch(StringPatch other) {
    __isset_bit_vector.clear();
    __isset_bit_vector.or(other.__isset_bit_vector);
    if (other.isSetAssign()) {
      this.assign = TBaseHelper.deepCopy(other.assign);
    }
    this.clear = TBaseHelper.deepCopy(other.clear);
    if (other.isSetPrepend()) {
      this.prepend = TBaseHelper.deepCopy(other.prepend);
    }
    if (other.isSetAppend()) {
      this.append = TBaseHelper.deepCopy(other.append);
    }
  }

  public StringPatch deepCopy() {
    return new StringPatch(this);
  }

  public String getAssign() {
    return this.assign;
  }

  public StringPatch setAssign(String assign) {
    this.assign = assign;
    return this;
  }

  public void unsetAssign() {
    this.assign = null;
  }

  // Returns true if field assign is set (has been assigned a value) and false otherwise
  public boolean isSetAssign() {
    return this.assign != null;
  }

  public void setAssignIsSet(boolean __value) {
    if (!__value) {
      this.assign = null;
    }
  }

  public boolean isClear() {
    return this.clear;
  }

  public StringPatch setClear(boolean clear) {
    this.clear = clear;
    setClearIsSet(true);
    return this;
  }

  public void unsetClear() {
    __isset_bit_vector.clear(__CLEAR_ISSET_ID);
  }

  // Returns true if field clear is set (has been assigned a value) and false otherwise
  public boolean isSetClear() {
    return __isset_bit_vector.get(__CLEAR_ISSET_ID);
  }

  public void setClearIsSet(boolean __value) {
    __isset_bit_vector.set(__CLEAR_ISSET_ID, __value);
  }

  public String getPrepend() {
    return this.prepend;
  }

  public StringPatch setPrepend(String prepend) {
    this.prepend = prepend;
    return this;
  }

  public void unsetPrepend() {
    this.prepend = null;
  }

  // Returns true if field prepend is set (has been assigned a value) and false otherwise
  public boolean isSetPrepend() {
    return this.prepend != null;
  }

  public void setPrependIsSet(boolean __value) {
    if (!__value) {
      this.prepend = null;
    }
  }

  public String getAppend() {
    return this.append;
  }

  public StringPatch setAppend(String append) {
    this.append = append;
    return this;
  }

  public void unsetAppend() {
    this.append = null;
  }

  // Returns true if field append is set (has been assigned a value) and false otherwise
  public boolean isSetAppend() {
    return this.append != null;
  }

  public void setAppendIsSet(boolean __value) {
    if (!__value) {
      this.append = null;
    }
  }

  public void setFieldValue(int fieldID, Object __value) {
    switch (fieldID) {
    case ASSIGN:
      if (__value == null) {
        unsetAssign();
      } else {
        setAssign((String)__value);
      }
      break;

    case CLEAR:
      if (__value == null) {
        unsetClear();
      } else {
        setClear((Boolean)__value);
      }
      break;

    case PREPEND:
      if (__value == null) {
        unsetPrepend();
      } else {
        setPrepend((String)__value);
      }
      break;

    case APPEND:
      if (__value == null) {
        unsetAppend();
      } else {
        setAppend((String)__value);
      }
      break;

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
    case ASSIGN:
      return getAssign();

    case CLEAR:
      return new Boolean(isClear());

    case PREPEND:
      return getPrepend();

    case APPEND:
      return getAppend();

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof StringPatch))
      return false;
    StringPatch that = (StringPatch)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetAssign(), that.isSetAssign(), this.assign, that.assign)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.clear, that.clear)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetPrepend(), that.isSetPrepend(), this.prepend, that.prepend)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAppend(), that.isSetAppend(), this.append, that.append)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {assign, clear, prepend, append});
  }

  @Override
  public int compareTo(StringPatch other) {
    if (other == null) {
      // See java.lang.Comparable docs
      throw new NullPointerException();
    }

    if (other == this) {
      return 0;
    }
    int lastComparison = 0;

    lastComparison = Boolean.valueOf(isSetAssign()).compareTo(other.isSetAssign());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(assign, other.assign);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetClear()).compareTo(other.isSetClear());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(clear, other.clear);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetPrepend()).compareTo(other.isSetPrepend());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(prepend, other.prepend);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetAppend()).compareTo(other.isSetAppend());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(append, other.append);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    return 0;
  }

  public void read(TProtocol iprot) throws TException {
    TField __field;
    iprot.readStructBegin(metaDataMap);
    while (true)
    {
      __field = iprot.readFieldBegin();
      if (__field.type == TType.STOP) {
        break;
      }
      switch (__field.id)
      {
        case ASSIGN:
          if (__field.type == TType.STRING) {
            this.assign = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case CLEAR:
          if (__field.type == TType.BOOL) {
            this.clear = iprot.readBool();
            setClearIsSet(true);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case PREPEND:
          if (__field.type == TType.STRING) {
            this.prepend = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case APPEND:
          if (__field.type == TType.STRING) {
            this.append = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(iprot, __field.type);
          break;
      }
      iprot.readFieldEnd();
    }
    iprot.readStructEnd();


    // check for required fields of primitive type, which can't be checked in the validate method
    validate();
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.assign != null) {
      if (isSetAssign()) {
        oprot.writeFieldBegin(ASSIGN_FIELD_DESC);
        oprot.writeString(this.assign);
        oprot.writeFieldEnd();
      }
    }
    oprot.writeFieldBegin(CLEAR_FIELD_DESC);
    oprot.writeBool(this.clear);
    oprot.writeFieldEnd();
    if (this.prepend != null) {
      oprot.writeFieldBegin(PREPEND_FIELD_DESC);
      oprot.writeString(this.prepend);
      oprot.writeFieldEnd();
    }
    if (this.append != null) {
      oprot.writeFieldBegin(APPEND_FIELD_DESC);
      oprot.writeString(this.append);
      oprot.writeFieldEnd();
    }
    oprot.writeFieldStop();
    oprot.writeStructEnd();
  }

  @Override
  public String toString() {
    return toString(1, true);
  }

  @Override
  public String toString(int indent, boolean prettyPrint) {
    String indentStr = prettyPrint ? TBaseHelper.getIndentedString(indent) : "";
    String newLine = prettyPrint ? "\n" : "";
    String space = prettyPrint ? " " : "";
    StringBuilder sb = new StringBuilder("StringPatch");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    if (isSetAssign())
    {
      sb.append(indentStr);
      sb.append("assign");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getAssign() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getAssign(), indent + 1, prettyPrint));
      }
      first = false;
    }
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("clear");
    sb.append(space);
    sb.append(":").append(space);
    sb.append(TBaseHelper.toString(this.isClear(), indent + 1, prettyPrint));
    first = false;
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("prepend");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getPrepend() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getPrepend(), indent + 1, prettyPrint));
    }
    first = false;
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("append");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getAppend() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getAppend(), indent + 1, prettyPrint));
    }
    first = false;
    sb.append(newLine + TBaseHelper.reduceIndent(indentStr));
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws TException {
    // check for required fields
  }

}

