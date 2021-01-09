#include <cuda_runtime.h>
#include <cassert>
#include <thread>

#include "cuda_stream_manager.h"

void CudaStreamManager::sync(int i) {
	if (i > -1) {
		cudaStreamSynchronize(streams[i]);
		return;
	}
	for (size_t i=0; i<MAX_STREAMS; ++i) {
		cudaStreamSynchronize(streams[i]);
	}
}
