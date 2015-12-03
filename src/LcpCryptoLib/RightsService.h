#ifndef __RIGHTS_SERVICE_H__
#define __RIGHTS_SERVICE_H__

#include "Public/IRightsService.h"

namespace lcp
{
    class IRightsManager;
    class IStorageProvider;

    class RightsService : public IRightsService
    {
    public:
        explicit RightsService(IStorageProvider * storageProvider, const std::string & unknownUserId);
        void SyncRightsFromStorage(ILicense * license);

    public:
        // IRightsService
        virtual bool HasRight(ILicense * license, const std::string & rightId) const;
        virtual bool Consume(ILicense * license, const std::string & rightId);
        virtual bool Consume(ILicense * license, const std::string & rightId, int amount);
        virtual void SetValue(ILicense * license, const std::string & rightId, const std::string & value);
        virtual std::string GetValue(ILicense * license, const std::string & rightId) const;

    private:
        IRightsManager * PerformChecks(ILicense * license) const;
        std::string BuildStorageProviderRightsKeyPrefix(ILicense * license) const;
        std::string BuildStorageProviderRightsKey(ILicense * license, const std::string & rightId) const;
        std::string ExtractRightsKey(const std::string & storageProviderKey) const;

    private:
        IStorageProvider * m_storageProvider;
        std::string m_unknownUserId;
    };
}

#endif //__RIGHTS_SERVICE_H__
