#pragma once

#include <steem/protocol/types.hpp>

#include <fc/array.hpp>
#include <vector>

#define STEEM_NUM_RESOURCE_TYPES     3

namespace steem { namespace protocol {
struct signed_transaction;
} } // steem::protocol

namespace steem { namespace plugins { namespace rc {

enum rc_resource_types
{
   resource_history_bytes,
   resource_new_accounts,
   resource_market_bytes
};

typedef fc::array< int64_t, STEEM_NUM_RESOURCE_TYPES > resource_count_type;

struct count_resources_result
{
   int32_t                                        market_op_count = 0;
   int32_t                                        new_account_op_count = 0;
   resource_count_type                            resource_count;
};

void count_resources(
   const steem::protocol::signed_transaction& tx,
   count_resources_result& result );

} } } // steem::plugins::rc

FC_REFLECT_ENUM( steem::plugins::rc::rc_resource_types,
    (resource_history_bytes)
    (resource_new_accounts)
    (resource_market_bytes)
   )
