#include "string"

#include "DeepSeekWrapper.h"

// Initialize static instance
DeepSeekWrapper* DeepSeekWrapper::m_pInstance = nullptr;

// Private Constructor
DeepSeekWrapper::DeepSeekWrapper()
{
}

// Singleton instance retrieval
DeepSeekWrapper* DeepSeekWrapper::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new DeepSeekWrapper{};
	}

	return m_pInstance;
}

std::string DeepSeekWrapper::getResponse(std::string sQuestion)
{
	std::string sResponse;

	//Get response

	return sResponse;
}

//C:\Users\sarim\OneDrive\Documents\Projects\DeepSeek\deepseek_env\Scripts\python.exe