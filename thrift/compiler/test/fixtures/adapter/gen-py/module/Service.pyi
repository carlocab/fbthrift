#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
import typing as __T

from thrift import Thrift
from thrift.protocol.TProtocol import TProtocolBase

import thrift.annotation.cpp.ttypes
import thrift.annotation.thrift.ttypes
import my
from module.ttypes import *


class Iface:  # Service
    def func(self, arg1: str, arg2: str, arg3: Foo) -> int: ...

class Client(Iface, __T.ContextManager[Client]):  # Service
    def __init__(self, iprot: __T.Optional[TProtocolBase], oprot: __T.Optional[TProtocolBase] = None, cpp_transport: __T.Optional[__T.TypeVar("SyncClient")] = None) -> None: ...
    def set_persistent_header(self, key: str, value: str) -> None: ...
    def set_onetime_header(self, key: str, value: str) -> None: ...
    def send_func(self, arg1: __T.Optional[str] = ..., arg2: __T.Optional[str] = ..., arg3: __T.Optional[Foo] = ...) -> None: ...
    def recv_func(self) -> int: ...

class Processor(Iface, Thrift.TProcessor):  # Service
    def __init__(self, handler: Iface) -> None:
        self._handler: Iface
        self._onewayMethods: __T.Sequence[__T.Callable]
        self._processMap: __T.Dict[str, __T.Callable]

    def process_func(self, seqid: int, iprot: TProtocolBase, oprot: TProtocolBase, server_ctx: __T.Any = ...) -> None: ...
    def process_main(self, iprot: TProtocolBase, oprot: TProtocolBase, server_ctx: __T.Any = ...) -> __T.Optional[bool]: ...
    def onewayMethods(self) -> __T.Tuple[__T.Callable]: ...

class func_args:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self,
        arg1: __T.Optional[str] = ...,
        arg2: __T.Optional[str] = ...,
        arg3: __T.Optional[Foo] = ...
    ) -> None:
        self.arg1: __T.Optional[str]
        self.arg2: __T.Optional[str]
        self.arg3: __T.Optional[Foo]

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...

class func_result:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(self, success: int = ...) -> None:
        self.success: int

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...
