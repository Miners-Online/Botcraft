#pragma once

#if PROTOCOL_VERSION >= 763 /* > 1.20.1 */
#include "protocolCraft/NetworkType.hpp"
#include "protocolCraft/Types/Slot.hpp"

namespace ProtocolCraft
{
    class CreateProcessingOutput : public NetworkType
    {
    public:
        virtual ~CreateProcessingOutput() override
        {

        }


        void SetItem(const Slot& item_)
        {
            item = item_;
        }
        

        const Slot& GetItem() const
        {
            return item;
        }

        void SetChance(const float& chance_)
        {
            chance = chance_;
        }
        

        const float& GetChance() const
        {
            return chance;
        }

    protected:
        virtual void ReadImpl(ReadIterator& iter, size_t& length) override
        {
            item = ReadData<Slot>(iter, length);
            chance = ReadData<float>(iter, length);
        }

        virtual void WriteImpl(WriteContainer& container) const override
        {
            WriteData<Slot>(item, container);
            WriteData<float>(chance, container);
        }

        virtual Json::Value SerializeImpl() const override
        {
            Json::Value output;

            output["item"] = item;
            output["chance"] = chance;

            return output;
        }

    private:
        Slot item;
        float chance;
    };
}
#endif
