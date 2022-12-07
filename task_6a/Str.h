#include "_str.h"


class Str {

	_str* m_pStr;

public:

	Str() { m_pStr = new _str; }		//если не копия, то создаем
	Str(const char * p) {		// новый ресурс
		m_pStr = new _str(p);
	}

    Str (const Str &s) {
	    m_pStr = s.m_pStr; 	// ссылаемся на тот же ресурс
	    m_pStr->AddRef(); 	// отмечаем, что сослались
    }

	~Str() { 
		m_pStr->Release(); 	// Не уничтожаем ресурс!
	}				// Уменьшаем счетчик ссылок!

	int len() const {
		return strlen(m_pStr->m_pszData); 
	}

    Str& operator = (const Str &s) {

        if (this != &s) {
            s.m_pStr -> AddRef(); // Важен порядок?!
            m_pStr -> Release();
            m_pStr = s.m_pStr;
        }

        return *this;
    }

    Str & operator += (const Str &s) {
        int length = len() + s.len();
        if (s.len() != 0) {			// добавление ничего не изменит!
            _str *pstrTmp = new _str; 	// Новый ресурс
            delete[] pstrTmp->m_pszData;

            pstrTmp->m_pszData = new char [length + 1];
            strcpy(pstrTmp->m_pszData, m_pStr->m_pszData);
            strcat(pstrTmp->m_pszData, s.m_pStr->m_pszData);

            m_pStr->Release();
            m_pStr = pstrTmp;
        }
        return *this;
    }

    operator const char*() const { return m_pStr->m_pszData; }

    

    void reverse(){

        bool is_polindrome = true; 

        _str* pstrTmp = new _str(m_pStr->m_pszData);
        std::size_t len = strlen(m_pStr->m_pszData);

        for (std::size_t i = 0; i < len / 2; i++){
            
            if (pstrTmp->m_pszData[i] != pstrTmp->m_pszData[len - i - 1]) {

                char tmp = pstrTmp->m_pszData[i];
                pstrTmp->m_pszData[i] = pstrTmp->m_pszData[len - i - 1];
                pstrTmp->m_pszData[len - i - 1] = tmp;

                is_polindrome = false;
            }
        }

        if (!is_polindrome){
            m_pStr->Release();
            m_pStr = pstrTmp;
        }
    }
};