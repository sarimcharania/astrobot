#pragma once
class DeepSeekWrapper
{
private:
	static DeepSeekWrapper* m_pInstance;
	DeepSeekWrapper();

public:
	static DeepSeekWrapper* getInstance();

	std::string getResponse(std::string sQuestion);
};

