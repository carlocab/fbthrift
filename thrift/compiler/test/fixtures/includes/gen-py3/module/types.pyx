#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from libcpp.memory cimport shared_ptr, make_shared, unique_ptr, make_unique
from libcpp.string cimport string
from libcpp cimport bool as cbool
from libcpp.iterator cimport inserter as cinserter
from cpython cimport bool as pbool
from libc.stdint cimport int8_t, int16_t, int32_t, int64_t, uint32_t
from cython.operator cimport dereference as deref, preincrement as inc
import thrift.py3.types
cimport thrift.py3.types
cimport thrift.py3.exceptions
from thrift.py3.types import NOTSET
cimport thrift.py3.std_libcpp as std_libcpp
from thrift.py3.serializer cimport IOBuf
from thrift.py3.serializer import Protocol
cimport thrift.py3.serializer as serializer

import sys
from collections.abc import Sequence, Set, Mapping, Iterable
from enum import Enum
cimport includes.types
import includes.types




cdef class MyStruct(thrift.py3.types.Struct):

    def __init__(
        MyStruct self,
        MyIncludedField=None,
        MyIncludedInt=None
    ):
        self.c_MyStruct = make_shared[cMyStruct]()

        inst = self
        cdef shared_ptr[includes.types.cIncluded] __MyIncludedField
        if MyIncludedField is not None:
            __MyIncludedField = (
            <includes.types.Included?> MyIncludedField).c_Included
            deref(inst.c_MyStruct).MyIncludedField = deref(__MyIncludedField.get())
            deref(inst.c_MyStruct).__isset.MyIncludedField = True

        if MyIncludedInt is not None:
            deref(inst.c_MyStruct).MyIncludedInt = MyIncludedInt
            deref(inst.c_MyStruct).__isset.MyIncludedInt = True


    cdef bytes _serialize(MyStruct self, proto):
        cdef string c_str
        if proto is Protocol.COMPACT:
            serializer.CompactSerialize[cMyStruct](deref(self.c_MyStruct.get()), &c_str)
        elif proto is Protocol.BINARY:
            serializer.BinarySerialize[cMyStruct](deref(self.c_MyStruct.get()), &c_str)
        elif proto is Protocol.JSON:
            serializer.JSONSerialize[cMyStruct](deref(self.c_MyStruct.get()), &c_str)
        return <bytes> c_str

    cdef uint32_t _deserialize(MyStruct self, const IOBuf* buf, proto):
        cdef uint32_t needed
        if proto is Protocol.COMPACT:
            needed = serializer.CompactDeserialize[cMyStruct](buf, deref(self.c_MyStruct.get()))
        elif proto is Protocol.BINARY:
            needed = serializer.BinaryDeserialize[cMyStruct](buf, deref(self.c_MyStruct.get()))
        elif proto is Protocol.JSON:
            needed = serializer.JSONDeserialize[cMyStruct](buf, deref(self.c_MyStruct.get()))
        return needed

    def __call__(
        MyStruct self,
        MyIncludedField=NOTSET,
        MyIncludedInt=NOTSET
    ):
        changes = any((
            MyIncludedField is not NOTSET,

            MyIncludedInt is not NOTSET,
        ))

        if not changes:
            return self

        inst = <MyStruct>MyStruct.__new__(MyStruct)
        inst.c_MyStruct = make_shared[cMyStruct](deref(self.c_MyStruct))
        cdef MyStruct defaults = MyStruct_defaults

        # Convert None's to default value.
        if MyIncludedField is None:
            deref(inst.c_MyStruct).MyIncludedField = deref(defaults.c_MyStruct).MyIncludedField
            deref(inst.c_MyStruct).__isset.MyIncludedField = False
        if MyIncludedField is NOTSET:
            MyIncludedField = None
        if MyIncludedInt is None:
            deref(inst.c_MyStruct).MyIncludedInt = deref(defaults.c_MyStruct).MyIncludedInt
            deref(inst.c_MyStruct).__isset.MyIncludedInt = False
        if MyIncludedInt is NOTSET:
            MyIncludedInt = None

        cdef shared_ptr[includes.types.cIncluded] __MyIncludedField
        if MyIncludedField is not None:
            __MyIncludedField = (
            <includes.types.Included?> MyIncludedField).c_Included
            deref(inst.c_MyStruct).MyIncludedField = deref(__MyIncludedField.get())
            deref(inst.c_MyStruct).__isset.MyIncludedField = True

        if MyIncludedInt is not None:
            deref(inst.c_MyStruct).MyIncludedInt = MyIncludedInt
            deref(inst.c_MyStruct).__isset.MyIncludedInt = True

        return inst

    def __iter__(self):
        yield 'MyIncludedField', self.MyIncludedField
        yield 'MyIncludedInt', self.MyIncludedInt

    def __bool__(self):
        return deref(self.c_MyStruct).__isset.MyIncludedField or deref(self.c_MyStruct).__isset.MyIncludedInt

    @staticmethod
    cdef create(shared_ptr[cMyStruct] c_MyStruct):
        inst = <MyStruct>MyStruct.__new__(MyStruct)
        inst.c_MyStruct = c_MyStruct
        return inst

    @property
    def MyIncludedField(self):

        cdef shared_ptr[includes.types.cIncluded] item
        if self.__MyIncludedField is None:
            item = make_shared[includes.types.cIncluded](
                deref(self.c_MyStruct).MyIncludedField)
            self.__MyIncludedField = includes.types.Included.create(item)
        return self.__MyIncludedField
        

    @property
    def MyIncludedInt(self):

        return self.c_MyStruct.get().MyIncludedInt


    def __richcmp__(self, other, op):
        cdef int cop = op
        if cop not in (2, 3):
            raise TypeError("unorderable types: {}, {}".format(self, other))
        if not (
                isinstance(self, MyStruct) and
                isinstance(other, MyStruct)):
            if cop == 2:  # different types are never equal
                return False
            else:         # different types are always notequal
                return True

        cdef cMyStruct cself = deref((<MyStruct>self).c_MyStruct)
        cdef cMyStruct cother = deref((<MyStruct>other).c_MyStruct)
        cdef cbool cmp = cself == cother
        if cop == 2:
            return cmp
        return not cmp

    def __hash__(MyStruct self):
        if not self.__hash:
            self.__hash = hash((
            self.MyIncludedField,
            self.MyIncludedInt,
            ))
        return self.__hash

    def __repr__(MyStruct self):
        return f'MyStruct(MyIncludedField={repr(self.MyIncludedField)}, MyIncludedInt={repr(self.MyIncludedInt)})'


MyStruct_defaults = MyStruct()


