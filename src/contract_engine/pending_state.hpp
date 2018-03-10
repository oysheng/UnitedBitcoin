#pragma once

#include <validation.h>
#include <contract_storage/contract_storage.hpp>


namespace blockchain {
    namespace contract {
        struct PendingState
        {
            PendingState(::contract::storage::ContractStorageService* _storage_service);
            virtual ~PendingState(){}

			::contract::storage::ContractStorageService* storage_service;

            std::unordered_map<std::string, ContractInfo> pending_contracts_to_create;
			std::vector<std::pair<std::string, StorageChanges>> contract_storage_changes; // contract_id => changes
            std::vector<ContractResultTransferInfo> balance_changes;
			// TODO: events, etc.

            void add_balance_change(const std::string& address, bool is_contract, bool add, uint64_t amount);
        };
    }
}