<?hh
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

/**
 * Original thrift struct:-
 * RequiresBackwardCompatibility
 */
<<\ThriftTypeInfo(shape('uri' => 'facebook.com/thrift/annotation/thrift/RequiresBackwardCompatibility'))>>
class facebook_thrift_annotation_thrift_RequiresBackwardCompatibility implements \IThriftSyncStruct, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'field_name',
      'type' => \TType::BOOL,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'field_name' => 1,
  ];

  const type TConstructorShape = shape(
    ?'field_name' => ?bool,
  );

  const type TShape = shape(
    'field_name' => bool,
  );
  const int STRUCTURAL_ID = 4755373036761315562;
  /**
   * Original thrift field:-
   * 1: bool field_name
   */
  public bool $field_name;

  public function __construct(?bool $field_name = null  )[] {
    $this->field_name = $field_name ?? false;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'field_name'),
    );
  }

  public function getName()[]: string {
    return 'RequiresBackwardCompatibility';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "thrift.RequiresBackwardCompatibility",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_BOOL_TYPE,
                )
              ),
              "name" => "field_name",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TStructAnnotations {
    return shape(
      'struct' => dict[
        'facebook_thrift_annotation_Struct' => facebook_thrift_annotation_Struct::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_Union' => facebook_thrift_annotation_Union::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_Exception' => facebook_thrift_annotation_Exception::fromShape(
          shape(
          )
        ),
      ],
      'fields' => dict[
      ],
    );
  }

  public static function __stringifyMapKeys<T>(Map<arraykey, T> $m)[]: Map<string, T> {
    $new = dict[];
    foreach ($m as $k => $v) {
      $new[(string)$k] = $v;
    }
    return new Map($new);
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
      $shape['field_name'],
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
      'field_name' => $this->field_name,
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

    if (idx($parsed, 'field_name') !== null) {
      $this->field_name = /* HH_FIXME[4110] */ $parsed['field_name'];
    }    
  }

}

/**
 * Original thrift struct:-
 * Experimental
 */
class facebook_thrift_annotation_thrift_Experimental implements \IThriftSyncStruct, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const type TShape = shape(
  );
  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct(  )[] {
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'Experimental';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "thrift.Experimental",
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TStructAnnotations {
    return shape(
      'struct' => dict[
        'facebook_thrift_annotation_Definition' => facebook_thrift_annotation_Definition::fromShape(
          shape(
          )
        ),
      ],
      'fields' => dict[
      ],
    );
  }

  public static function __stringifyMapKeys<T>(Map<arraykey, T> $m)[]: Map<string, T> {
    $new = dict[];
    foreach ($m as $k => $v) {
      $new[(string)$k] = $v;
    }
    return new Map($new);
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

  }

}

/**
 * Original thrift struct:-
 * Deprecated
 */
class facebook_thrift_annotation_thrift_Deprecated implements \IThriftSyncStruct, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const type TShape = shape(
  );
  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct(  )[] {
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'Deprecated';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "thrift.Deprecated",
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TStructAnnotations {
    return shape(
      'struct' => dict[
        'facebook_thrift_annotation_thrift_Experimental' => facebook_thrift_annotation_thrift_Experimental::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_Definition' => facebook_thrift_annotation_Definition::fromShape(
          shape(
          )
        ),
      ],
      'fields' => dict[
      ],
    );
  }

  public static function __stringifyMapKeys<T>(Map<arraykey, T> $m)[]: Map<string, T> {
    $new = dict[];
    foreach ($m as $k => $v) {
      $new[(string)$k] = $v;
    }
    return new Map($new);
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

  }

}

/**
 * Original thrift struct:-
 * TerseWrite
 */
<<\ThriftTypeInfo(shape('uri' => 'facebook.com/thrift/annotation/thrift/TerseWrite'))>>
class facebook_thrift_annotation_thrift_TerseWrite implements \IThriftSyncStruct, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const type TShape = shape(
  );
  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct(  )[] {
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'TerseWrite';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "thrift.TerseWrite",
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TStructAnnotations {
    return shape(
      'struct' => dict[
        'facebook_thrift_annotation_Program' => facebook_thrift_annotation_Program::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_Field' => facebook_thrift_annotation_Field::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_Struct' => facebook_thrift_annotation_Struct::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_thrift_Experimental' => facebook_thrift_annotation_thrift_Experimental::fromShape(
          shape(
          )
        ),
      ],
      'fields' => dict[
      ],
    );
  }

  public static function __stringifyMapKeys<T>(Map<arraykey, T> $m)[]: Map<string, T> {
    $new = dict[];
    foreach ($m as $k => $v) {
      $new[(string)$k] = $v;
    }
    return new Map($new);
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

  }

}

/**
 * Original thrift struct:-
 * Box
 */
<<\ThriftTypeInfo(shape('uri' => 'facebook.com/thrift/annotation/thrift/Box'))>>
class facebook_thrift_annotation_thrift_Box implements \IThriftSyncStruct, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const type TShape = shape(
  );
  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct(  )[] {
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'Box';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "thrift.Box",
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TStructAnnotations {
    return shape(
      'struct' => dict[
        'facebook_thrift_annotation_Field' => facebook_thrift_annotation_Field::fromShape(
          shape(
          )
        ),
      ],
      'fields' => dict[
      ],
    );
  }

  public static function __stringifyMapKeys<T>(Map<arraykey, T> $m)[]: Map<string, T> {
    $new = dict[];
    foreach ($m as $k => $v) {
      $new[(string)$k] = $v;
    }
    return new Map($new);
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

  }

}

/**
 * Original thrift struct:-
 * SerializeInFieldIdOrder
 */
<<\ThriftTypeInfo(shape('uri' => 'facebook.com/thrift/annotation/thrift/SerializeInFieldIdOrder'))>>
class facebook_thrift_annotation_thrift_SerializeInFieldIdOrder implements \IThriftSyncStruct, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const type TShape = shape(
  );
  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct(  )[] {
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'SerializeInFieldIdOrder';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "thrift.SerializeInFieldIdOrder",
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TStructAnnotations {
    return shape(
      'struct' => dict[
        'facebook_thrift_annotation_Struct' => facebook_thrift_annotation_Struct::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_thrift_Experimental' => facebook_thrift_annotation_thrift_Experimental::fromShape(
          shape(
          )
        ),
      ],
      'fields' => dict[
      ],
    );
  }

  public static function __stringifyMapKeys<T>(Map<arraykey, T> $m)[]: Map<string, T> {
    $new = dict[];
    foreach ($m as $k => $v) {
      $new[(string)$k] = $v;
    }
    return new Map($new);
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

  }

}

/**
 * Original thrift struct:-
 * NoLegacyApi
 */
<<\ThriftTypeInfo(shape('uri' => 'facebook.com/thrift/annotation/thrift/NoLegacyApi'))>>
class facebook_thrift_annotation_thrift_NoLegacyApi implements \IThriftSyncStruct, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const type TShape = shape(
  );
  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct(  )[] {
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'NoLegacyApi';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "thrift.NoLegacyApi",
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TStructAnnotations {
    return shape(
      'struct' => dict[
        'facebook_thrift_annotation_Program' => facebook_thrift_annotation_Program::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_Struct' => facebook_thrift_annotation_Struct::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_Union' => facebook_thrift_annotation_Union::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_Exception' => facebook_thrift_annotation_Exception::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_Service' => facebook_thrift_annotation_Service::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_thrift_Experimental' => facebook_thrift_annotation_thrift_Experimental::fromShape(
          shape(
          )
        ),
      ],
      'fields' => dict[
      ],
    );
  }

  public static function __stringifyMapKeys<T>(Map<arraykey, T> $m)[]: Map<string, T> {
    $new = dict[];
    foreach ($m as $k => $v) {
      $new[(string)$k] = $v;
    }
    return new Map($new);
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

  }

}

/**
 * Original thrift struct:-
 * v1
 */
class facebook_thrift_annotation_thrift_v1 implements \IThriftSyncStruct, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
  ];
  const dict<string, int> FIELDMAP = dict[
  ];

  const type TConstructorShape = shape(
  );

  const type TShape = shape(
  );
  const int STRUCTURAL_ID = 957977401221134810;

  public function __construct(  )[] {
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
    );
  }

  public function getName()[]: string {
    return 'v1';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "thrift.v1",
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TStructAnnotations {
    return shape(
      'struct' => dict[
        'facebook_thrift_annotation_thrift_TerseWrite' => facebook_thrift_annotation_thrift_TerseWrite::fromShape(
          shape(
          )
        ),
        'facebook_thrift_annotation_FbthriftInternalScopeTransitive' => facebook_thrift_annotation_FbthriftInternalScopeTransitive::fromShape(
          shape(
          )
        ),
      ],
      'fields' => dict[
      ],
    );
  }

  public static function __stringifyMapKeys<T>(Map<arraykey, T> $m)[]: Map<string, T> {
    $new = dict[];
    foreach ($m as $k => $v) {
      $new[(string)$k] = $v;
    }
    return new Map($new);
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

  }

}

