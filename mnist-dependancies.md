# MNIST Dependencies for Streamlining

### Mrinal Ghosh, Sharith Godamanna & Alexander Trinh

- kad_trap_fe

- kann_srand

- kann_load
    - kann_load_fp
        - kad_size_const
        - kad_size_var
        - kad_load
        - kad_ext_sync

- kad_feed
    - kad_vleaf

- kad_relu
    - KAD_FUNC_OP1
        - kad_op1_core

- kann_layer_conv2d `!!!`
    - kann_new_weight_conv2d
        - kann_new_leaf
        - kann_new_leaf_array
        - kad_len
        - kad_drand_normal
        - kad_drand
        - kad_xoroshiro128plus_next

- kad_max2d
    - kad_new_core
    - conv2d_gen_aux
        - conv_find_par
    - kad_finalize_node
        - kad_is_back

- kann_layer_dropout
    - kann_layer_dropout2
        - kann_new_leaf2
            - kann_new_leaf_array
                - kad_drand_normal
                - kad_len
        - kad_dropout
            - kad_op2_core
                - kad_new_core
                    - kad_finalize_node (...)
            - kad_rng
                - kad_xoroshiro128plus_jump
        - kad_switch
            - kad_new_core
            - kad_finalize_node (...)

- kann_layer_dense
    - ... `!!!`
    - kann_layer_dense2
        - kad_len
    - kann_new_leaf2 (...)
    - kad_add `!!!`
    - kad_cmul `!!!`

- kann_new
    - va_start
    - va_arg
    - va_end
    - kad_compile_array
        - kv_push
        - kv_pop
    - kad_allocate_internal
        - kad_mark_back
        - kad_is_back
        - kad_len
    - kad_is_pivot
    - kad_avg
        - kad_pooling_general
            - ...

- kann_layer_cost
    - kann_layer_dense
        - ...
    - kad_feed
        - ...
    - kad_sigm
        - KAD_FUNC_OP1 (6)
            - kad_op1_core
    - kad_ce_bin
        - KAD_FUNC_OP2 (22)
            - kad_op2_core
                - ...
    - kad_mse, kad_tanh, kad_ce_bin_neg, kad_softmax, kad_ce_multi `-`

- kann_data_read `kann_data.c/h`

- kann_mt
    - mt_destroy
    - kann_clone
        - kad_clone
            - kad_dup1
            - kad_is_feed
                - kad_is_ext
                - kad_is_back
            - kad_len  
        - kad_ext_collate
            - kad_size_var
            - kad_len
            - kad_is_const
            - kad_is_var

- kann_train_fnn1 `!!!`
    - kann_dim_in
    - kann_dim_out
    - kann_size_var
        - kad_size_var
    - kann_size_const
        - kad_size_const
    - kann_shuffle
        - kad_drand
            - kad_xoroshiro128plus_next
    - kann_feed_bind
        - kad_is_feed ...
        - chk_flg
        - chk_lbl

- kann_save

- kann_data_free

- kann_switch

- kann_dim_out

- kann_apply1

- kann_delete