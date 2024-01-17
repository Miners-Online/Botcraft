#pragma once

#if PROTOCOL_VERSION >= 763 /* > 1.20.1 */
#include "protocolCraft/Types/Recipes/RecipeTypeData.hpp"
#include "protocolCraft/Types/Recipes/Ingredient.hpp"
#include "protocolCraft/Types/Slot.hpp"

namespace ProtocolCraft
{
    class RecipeTypeCreateProcessing : public RecipeTypeData
    {
    public:
        virtual ~RecipeTypeCreateProcessing() override
        {

        }

        void SetGroup(const std::string& group_)
        {
            group = group_;
        }

        void SetIngredients(const std::vector<Ingredient>& ingredients_)
        {
            ingredients = ingredients_;
        }

        void SetResult(const Slot& result_)
        {
            result = result_;
        }


        const std::string& GetGroup() const
        {
            return group;
        }

        const std::vector<Ingredient>& GetIngredients() const
        {
            return ingredients;
        }

        const Slot& GetResult() const
        {
            return result;
        }

    protected:
        virtual void ReadImpl(ReadIterator& iter, size_t& length) override
        {
            group = ReadData<std::string>(iter, length);
            ingredients = ReadVector<Ingredient>(iter, length);
            result = ReadData<Slot>(iter, length);
        }

        virtual void WriteImpl(WriteContainer& container) const override
        {
            WriteData<std::string>(group, container);
            WriteVector<Ingredient>(ingredients, container);
            WriteData<Slot>(result, container);
        }

        virtual Json::Value SerializeImpl() const override
        {
            Json::Value output;

            output["group"] = group;
            output["ingredient"] = ingredients;
            output["result"] = result;

            return output;
        }

    private:
        std::string group;
        std::vector<Ingredient> ingredients;
        Slot result;
    };
}
#endif
