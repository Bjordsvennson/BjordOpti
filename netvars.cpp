
#include "netvars.h"
#include "client.h"

void NetVars::Init(void)
{
	m_pClasses = client->GetAllClasses();

	while (m_pClasses)
	{
		m_pTables.push_back(m_pClasses->m_pRecvTable);
		m_pClasses = m_pClasses->m_pNext;
	}
}

int NetVars::RecurseForOffset(RecvTable* pTable, char* childname)
{
	m_ExtraOffset = 0;

	for (int i = 0; i < pTable->m_nProps; i++)
	{
		RecvProp* pProp = &pTable->m_pProps[i];
		RecvTable* pChildTable = pProp->m_pDataTable;

		if (pChildTable && pChildTable->m_nProps > 0)
		{
			int extra = RecurseForOffset(pChildTable, childname);
			if (extra)
			{
				return m_ExtraOffset += extra;
			}
		}

		if (!strcmp(pProp->m_pVarName, childname))
		{
			return pProp->m_Offset + m_ExtraOffset;
		}
	}
	return 0;
}

RecvProp* NetVars::RecurseForProp(RecvTable* pTable, char* childname)
{
	for (int i = 0; i < pTable->m_nProps; i++)
	{
		RecvProp* pProp = &pTable->m_pProps[i];
		RecvTable* pChildTable = pProp->m_pDataTable;

		if (pChildTable && pChildTable->m_nProps > 0)
		{
			RecvProp* pChild = RecurseForProp(pChildTable, childname);
			if (pChild)
			{
				return pChild;
			}
		}

		if (!strcmp(pProp->m_pVarName, childname))
		{
			return pProp;
		}
	}
	return nullptr;
}

int NetVars::FindOffset(char* tablename, char* childname)
{
	for (RecvTable* pTable : m_pTables)
	{
		if (!strcmp(pTable->m_pNetTableName, tablename))
		{
			return RecurseForOffset(pTable, childname);
		}
	}
	
	return 0;
}

RecvProp* NetVars::FindProp(char* tablename, char* childname)
{
	for (RecvTable* pTable : m_pTables)
	{
		if (!strcmp(pTable->m_pNetTableName, tablename))
		{
			return RecurseForProp(pTable, childname);
		}
	}
	
	return nullptr;
}

NetVars netvars;
