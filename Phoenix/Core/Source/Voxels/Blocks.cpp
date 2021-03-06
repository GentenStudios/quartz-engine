// Copyright 2019 Genten Studios
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include <Core/Voxels/Blocks.hpp>

using namespace phoenix::voxels;

RegisteredBlock::RegisteredBlock(const std::string& unique, BlockID id,
                                 const std::string& display)
    : uniqueName(unique), blockId(id), displayName(display) {};

RegisteredBlock::~RegisteredBlock() = default;

BlockRegistry::BlockRegistry(){};

BlockID BlockRegistry::registerBlock(const std::string& uniqueName,
                                 const std::string& displayName)
{	
	BlockID exists = getBlockId(uniqueName);
	if (exists == -1){
		m_blocks.push_back(RegisteredBlock(uniqueName, m_blocks.size(), displayName));
		return m_blocks.size() - 1;
	} else {
		m_blocks[exists].displayName = displayName;
		m_blocks[exists].uniqueName = uniqueName;
		return exists;
	}

};

const std::string& BlockRegistry::getDisplayName(BlockID blockId)
{
	if (blockId < m_blocks.size()){
		return m_blocks[blockId].displayName;
	}else{
		static const std::string error {"ERROR"};
		return error;
	}
};

BlockID BlockRegistry::getBlockId(const std::string& uniqueName)
{
	for (BlockID i = 0; i < m_blocks.size(); i++)
	{
		if (m_blocks[i].uniqueName == uniqueName)
		{
			return i;
		};
	}
	return -1;
}