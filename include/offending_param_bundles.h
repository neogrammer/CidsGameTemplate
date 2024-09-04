#pragma once
#include <variant>
namespace cid
{
	enum class OffendingParameterBundleType
	{
		TransformParams,
		Count,
		NotSet
	};

	struct TransformParamBundle
	{
		float posx, posy;
		float velx, vely;
		bool facingRight;
	};


	using ParamBundleVariant = std::variant<TransformParamBundle>;

}

