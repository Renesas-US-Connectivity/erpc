# Copyright 2017 NXP
# All rights reserved.
#
#
# SPDX-License-Identifier: BSD-3-Clause

#
# Generated by erpcgen 1.14.0 on Wed May 28 10:34:55 2025.
#
# AUTOGENERATED - DO NOT EDIT
#

import erpc
from . import common, interface

# Client for MatrixMultiplyService
class MatrixMultiplyServiceClient(interface.IMatrixMultiplyService):
    def __init__(self, manager):
        super(MatrixMultiplyServiceClient, self).__init__()
        self._clientManager = manager

    def erpcMatrixMultiply(self, matrix1, matrix2, result_matrix):
        assert type(result_matrix) is erpc.Reference, "out parameter must be a Reference object"

        # Build remote function invocation message.
        request = self._clientManager.create_request()
        codec = request.codec
        codec.start_write_message(erpc.codec.MessageInfo(
                type=erpc.codec.MessageType.kInvocationMessage,
                service=self.SERVICE_ID,
                request=self.ERPCMATRIXMULTIPLY_ID,
                sequence=request.sequence))
        if matrix1 is None:
            raise ValueError("matrix1 is None")
        for _i0 in matrix1:
            for _i1 in _i0:
                codec.write_int32(_i1)


        if matrix2 is None:
            raise ValueError("matrix2 is None")
        for _i0 in matrix2:
            for _i1 in _i0:
                codec.write_int32(_i1)



        # Send request and process reply.
        self._clientManager.perform_request(request)
        result_matrix.value = []
        for _i0 in range(5):
            _v0 = []
            for _i1 in range(5):
                _v1 = codec.read_int32()
                _v0.append(_v1)

            result_matrix.value.append(_v0)



