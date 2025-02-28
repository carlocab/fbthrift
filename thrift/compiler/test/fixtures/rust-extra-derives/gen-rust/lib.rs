// @generated by Thrift for src/mod.thrift
// This file is probably not the place you want to edit!

#![recursion_limit = "100000000"]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies, clippy::type_complexity)]

pub use self::errors::*;
pub use self::types::*;

/// Thrift type definitions for `mod`.
pub mod types {
    #![allow(clippy::redundant_closure)]


    #[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash, Foo, Bar)]
    pub struct WithCustomDerives {
        pub a: ::std::primitive::bool,
        // This field forces `..Default::default()` when instantiating this
        // struct, to make code future-proof against new fields added later to
        // the definition in Thrift. If you don't want this, add the annotation
        // `(rust.exhaustive)` to the Thrift struct to eliminate this field.
        #[doc(hidden)]
        pub _dot_dot_Default_default: self::dot_dot::OtherFields,
    }

    impl ::std::default::Default for self::WithCustomDerives {
        fn default() -> Self {
            Self {
                a: ::std::default::Default::default(),
                _dot_dot_Default_default: self::dot_dot::OtherFields(()),
            }
        }
    }

    impl ::std::fmt::Debug for self::WithCustomDerives {
        fn fmt(&self, formatter: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
            formatter
                .debug_struct("WithCustomDerives")
                .field("a", &self.a)
                .finish()
        }
    }

    unsafe impl ::std::marker::Send for self::WithCustomDerives {}
    unsafe impl ::std::marker::Sync for self::WithCustomDerives {}

    impl ::fbthrift::GetTType for self::WithCustomDerives {
        const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
    }

    impl<P> ::fbthrift::Serialize<P> for self::WithCustomDerives
    where
        P: ::fbthrift::ProtocolWriter,
    {
        fn write(&self, p: &mut P) {
            p.write_struct_begin("WithCustomDerives");
            p.write_field_begin("a", ::fbthrift::TType::Bool, 1);
            ::fbthrift::Serialize::write(&self.a, p);
            p.write_field_end();
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    impl<P> ::fbthrift::Deserialize<P> for self::WithCustomDerives
    where
        P: ::fbthrift::ProtocolReader,
    {
        fn read(p: &mut P) -> ::anyhow::Result<Self> {
            static FIELDS: &[::fbthrift::Field] = &[
                ::fbthrift::Field::new("a", ::fbthrift::TType::Bool, 1),
            ];
            let mut field_a = ::std::option::Option::None;
            let _ = p.read_struct_begin(|_| ())?;
            loop {
                let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
                match (fty, fid as ::std::primitive::i32) {
                    (::fbthrift::TType::Stop, _) => break,
                    (::fbthrift::TType::Bool, 1) => field_a = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                    (fty, _) => p.skip(fty)?,
                }
                p.read_field_end()?;
            }
            p.read_struct_end()?;
            ::std::result::Result::Ok(Self {
                a: field_a.unwrap_or_default(),
                _dot_dot_Default_default: self::dot_dot::OtherFields(()),
            })
        }
    }


    mod dot_dot {
        #[derive(Copy, Clone, PartialEq, Eq, PartialOrd, Ord, Hash)]
        pub struct OtherFields(pub(crate) ());

        #[allow(dead_code)] // if serde isn't being used
        pub(super) fn default_for_serde_deserialize() -> OtherFields {
            OtherFields(())
        }
    }
}

/// Error return types.
pub mod errors {
}
