#pragma once

#include "miner_work.hpp"
#include "xmrstak/misc/environment.hpp"

#include <atomic>


namespace xmrstak
{

struct GlobalStates
{

	static inline GlobalStates& inst()
	{
		auto& env = Environment::inst();
		if(env.pGlobalStates == nullptr)
			env.pGlobalStates = new GlobalStates;
		return *env.pGlobalStates;
	}

	void switch_work(miner_work& pWork);

	miner_work oGlobalWork;
	std::atomic<uint64_t> iGlobalJobNo;
	std::atomic<uint64_t> iConsumeCnt;
	uint64_t iThreadCount;

	private:

	GlobalStates() : iThreadCount(0)
	{
	}
	
};

} // namepsace xmrstak
