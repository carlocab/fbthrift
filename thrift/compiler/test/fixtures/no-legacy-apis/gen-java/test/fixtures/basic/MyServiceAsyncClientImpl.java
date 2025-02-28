/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basic;

import com.facebook.nifty.client.RequestChannel;
import com.facebook.swift.codec.*;
import com.facebook.swift.service.*;
import com.facebook.swift.service.metadata.*;
import com.facebook.thrift.client.*;
import com.facebook.thrift.util.FutureUtil;
import com.google.common.util.concurrent.ListenableFuture;
import java.io.*;
import java.lang.reflect.Method;
import java.util.*;
import org.apache.thrift.ProtocolId;
import reactor.core.publisher.Mono;

@SwiftGenerated
@Deprecated
public class MyServiceAsyncClientImpl extends AbstractThriftClient implements MyService.Async {

    // Method Handlers
    private ThriftMethodHandler queryMethodHandler;

    // Method Exceptions
    private static final Class[] queryExceptions = new Class[] {
        org.apache.thrift.TException.class};

    public MyServiceAsyncClientImpl(
        RequestChannel channel,
        Map<Method, ThriftMethodHandler> methods,
        Map<String, String> headers,
        Map<String, String> persistentHeaders,
        List<? extends ThriftClientEventHandler> eventHandlers) {
      super(channel, headers, persistentHeaders, eventHandlers);

      Map<String, ThriftMethodHandler> methodHandlerMap = new HashMap<>();
      methods.forEach(
          (key, value) -> {
            methodHandlerMap.put(key.getName(), value);
          });

      // Set method handlers
      queryMethodHandler = methodHandlerMap.get("query");
    }

    public MyServiceAsyncClientImpl(
        Map<String, String> headers,
        Map<String, String> persistentHeaders,
        Mono<? extends RpcClient> rpcClient,
        ThriftServiceMetadata serviceMetadata,
        ThriftCodecManager codecManager,
        ProtocolId protocolId,
        Map<Method, ThriftMethodHandler> methods) {
      super(headers, persistentHeaders, rpcClient, serviceMetadata, codecManager, protocolId);

      Map<String, ThriftMethodHandler> methodHandlerMap = new HashMap<>();
      methods.forEach(
          (key, value) -> {
            methodHandlerMap.put(key.getName(), value);
          });

      // Set method handlers
      queryMethodHandler = methodHandlerMap.get("query");
    }

    @java.lang.Override
    public void close() {
        super.close();
    }


    @java.lang.Override
    public ListenableFuture<test.fixtures.basic.MyStruct> query(
        test.fixtures.basic.MyUnion u) {
        return query(u, RpcOptions.EMPTY);
    }

    @java.lang.Override
    public ListenableFuture<test.fixtures.basic.MyStruct> query(
        test.fixtures.basic.MyUnion u,
        RpcOptions rpcOptions) {
        return FutureUtil.transform(queryWrapper(u, rpcOptions));
    }

    @java.lang.Override
    public ListenableFuture<ResponseWrapper<test.fixtures.basic.MyStruct>> queryWrapper(
        test.fixtures.basic.MyUnion u,
        RpcOptions rpcOptions) {
        try {
          return executeWrapperWithOptions(queryMethodHandler, queryExceptions, rpcOptions, u);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }
}
